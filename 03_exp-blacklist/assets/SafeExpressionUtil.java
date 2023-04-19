package .home.frank.Workspace.Java-Security.source-code.xwork-1.0.3-atlassian-10.com.opensymphony.xwork.util;

import com.google.common.cache.CacheBuilder;
import com.opensymphony.xwork.config.ConfigurationManager;
import com.opensymphony.xwork.util.OgnlUtil;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Optional;
import java.util.Set;
import javax.lang.model.SourceVersion;
import ognl.Node;
import ognl.OgnlContext;
import ognl.OgnlException;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

class SafeExpressionUtil {
  private static final Set<String> UNSAFE_VARIABLE_NAMES;
  
  private static final Set<String> UNSAFE_NODE_TYPES;
  
  private static final Optional<Method> OGNL_METHOD_GET_METHOD;
  
  private static final Optional<Field> OGNL_METHOD_GET_CLASS_STATIC_FIELD;
  
  private static final Log log = LogFactory.getLog(com.opensymphony.xwork.util.SafeExpressionUtil.class);
  
  private final Set<String> SAFE_EXPRESSIONS_CACHE = Collections.newSetFromMap(
      CacheBuilder.newBuilder()
      .maximumSize(10000L)
      .build().asMap());
  
  private final Set<String> UNSAFE_EXPRESSIONS_CACHE = Collections.newSetFromMap(
      CacheBuilder.newBuilder()
      .maximumSize(1000L)
      .build().asMap());
  
  private final Set<String> unsafePropertyNames;
  
  private final Set<String> unsafePackageNames;
  
  private final Set<String> unsafeMethodNames;
  
  private final Set<String> allowedClassNames;
  
  static {
    Method method;
  }
  
  static {
    Set<String> set = new HashSet<>();
    set.add("ognl.ASTStaticField");
    set.add("ognl.ASTCtor");
    set.add("ognl.ASTAssign");
    UNSAFE_NODE_TYPES = Collections.unmodifiableSet(set);
    set = new HashSet<>();
    set.add("#_memberAccess");
    set.add("#context");
    set.add("#request");
    set.add("#parameters");
    set.add("#session");
    set.add("#application");
    set.add("#attr");
    UNSAFE_VARIABLE_NAMES = Collections.unmodifiableSet(set);
    Field getStaticMethodClassName = null;
    try {
      Class<?> astStaticMethodClass = Class.forName("ognl.ASTStaticMethod");
      getStaticMethodClassName = astStaticMethodClass.getDeclaredField("className");
      getStaticMethodClassName.setAccessible(true);
    } catch (Exception exception) {}
    OGNL_METHOD_GET_CLASS_STATIC_FIELD = Optional.ofNullable(getStaticMethodClassName);
    try {
      Class<?> aClass = Class.forName("ognl.ASTMethod");
      method = aClass.getMethod("getMethodName", new Class[0]);
      method.setAccessible(true);
    } catch (Exception e) {
      method = null;
    } 
    OGNL_METHOD_GET_METHOD = Optional.ofNullable(method);
  }
  
  public SafeExpressionUtil() {
    this.unsafePropertyNames = getUnsafePropertyNames();
    this.unsafePackageNames = getUnsafePackageNames();
    this.unsafeMethodNames = getUnsafeMethodNames();
    this.allowedClassNames = getAllowedClassNames();
  }
  
  private Set<String> getUnsafePropertyNames() {
    Set<String> set = new HashSet<>(ConfigurationManager.getConfiguration().getExcludedClasses());
    set.add("class");
    set.add("classLoader");
    return set;
  }
  
  private Set<String> getUnsafePackageNames() {
    HashSet<String> blockedPackages = new HashSet<>(ConfigurationManager.getConfiguration().getExcludedPackageNames());
    return Collections.unmodifiableSet(blockedPackages);
  }
  
  private Set<String> getUnsafeMethodNames() {
    Set<String> set = new HashSet<>();
    set.add("getClass");
    set.add("getClassLoader");
    return Collections.unmodifiableSet(set);
  }
  
  private Set<String> getAllowedClassNames() {
    HashSet<String> allowedClassNames = new HashSet<>(ConfigurationManager.getConfiguration().getAllowedClasses());
    return Collections.unmodifiableSet(allowedClassNames);
  }
  
  public boolean isSafeExpression(String expression) {
    return isSafeExpressionInternal(expression, new HashSet<>());
  }
  
  private boolean isSafeExpressionInternal(String expression, Set<String> visitedExpressions) {
    if (!this.SAFE_EXPRESSIONS_CACHE.contains(expression)) {
      if (this.UNSAFE_EXPRESSIONS_CACHE.contains(expression))
        return false; 
      if (isUnSafeClass(expression)) {
        this.UNSAFE_EXPRESSIONS_CACHE.add(expression);
        return false;
      } 
      if (SourceVersion.isName(trimQuotes(expression)) && this.allowedClassNames.contains(trimQuotes(expression))) {
        this.SAFE_EXPRESSIONS_CACHE.add(expression);
      } else {
        try {
          Object parsedExpression = OgnlUtil.compile(expression);
          if (parsedExpression instanceof Node)
            if (containsUnsafeExpression((Node)parsedExpression, visitedExpressions)) {
              this.UNSAFE_EXPRESSIONS_CACHE.add(expression);
              log.debug(String.format("Unsafe clause found in [\" %s \"]", new Object[] { expression }));
            } else {
              this.SAFE_EXPRESSIONS_CACHE.add(expression);
            }  
        } catch (OgnlException|RuntimeException ex) {
          this.SAFE_EXPRESSIONS_CACHE.add(expression);
          log.debug("Cannot verify safety of OGNL expression", ex);
        } 
      } 
    } 
    return this.SAFE_EXPRESSIONS_CACHE.contains(expression);
  }
  
  private boolean containsUnsafeExpression(Node node, Set<String> visitedExpressions) {
    String nodeClassName = node.getClass().getName();
    if (UNSAFE_NODE_TYPES.contains(nodeClassName))
      return true; 
    if ("ognl.ASTStaticMethod".equals(nodeClassName) && !this.allowedClassNames.contains(getClassNameFromStaticMethod(node)))
      return true; 
    if ("ognl.ASTProperty".equals(nodeClassName) && isUnSafeClass(node.toString()))
      return true; 
    if ("ognl.ASTMethod".equals(nodeClassName) && this.unsafeMethodNames.contains(getMethodInOgnlExp(node)))
      return true; 
    if ("ognl.ASTVarRef".equals(nodeClassName) && UNSAFE_VARIABLE_NAMES.contains(node.toString()))
      return true; 
    if ("ognl.ASTConst".equals(nodeClassName) && !isSafeConstantExpressionNode(node, visitedExpressions))
      return true; 
    for (int i = 0; i < node.jjtGetNumChildren(); i++) {
      Node childNode = node.jjtGetChild(i);
      if (childNode != null && containsUnsafeExpression(childNode, visitedExpressions))
        return true; 
    } 
    return false;
  }
  
  private boolean isSafeConstantExpressionNode(Node node, Set<String> visitedExpressions) {
    try {
      String value = node.getValue(new OgnlContext(), null).toString();
      if (visitedExpressions.contains(value) || value == null || value.isEmpty())
        return true; 
      visitedExpressions.add(value);
      return isSafeExpressionInternal(value, visitedExpressions);
    } catch (OgnlException e) {
      log.debug("Cannot verify safety of OGNL expression", (Throwable)e);
      return true;
    } 
  }
  
  private static String getClassNameFromStaticMethod(Node node) {
    try {
      if (OGNL_METHOD_GET_CLASS_STATIC_FIELD.isPresent())
        return (String)((Field)OGNL_METHOD_GET_CLASS_STATIC_FIELD.get()).get(node); 
    } catch (IllegalAccessException e) {
      log.debug("Method can't be accessed for introspection", e);
    } 
    return null;
  }
  
  private static String getMethodInOgnlExp(Node node) {
    try {
      if (OGNL_METHOD_GET_METHOD.isPresent())
        return (String)((Method)OGNL_METHOD_GET_METHOD.get()).invoke(node, new Object[0]); 
    } catch (IllegalAccessException|java.lang.reflect.InvocationTargetException e) {
      log.debug("Method can't be accessed for introspection", e);
    } 
    return null;
  }
  
  private String trimQuotes(String value) {
    String trimmedValue = value.trim();
    if (trimmedValue.startsWith("\"") && trimmedValue.endsWith("\""))
      return trimQuotes(trimmedValue.substring(1, trimmedValue.length() - 1)); 
    if (trimmedValue.startsWith("'") && trimmedValue.endsWith("'"))
      return trimQuotes(trimmedValue.substring(1, trimmedValue.length() - 1)); 
    return value;
  }
  
  private boolean isUnSafeClass(String expression) {
    String trimmedClassName = trimQuotes(expression);
    if (this.unsafePropertyNames.contains(trimmedClassName))
      return true; 
    if (SourceVersion.isName(trimmedClassName)) {
      List<String> parentPackageNames = populateParentPackages(trimmedClassName, new ArrayList<>());
      Objects.requireNonNull(this.unsafePackageNames);
      return parentPackageNames.stream().anyMatch(this.unsafePackageNames::contains);
    } 
    return false;
  }
  
  private List<String> populateParentPackages(String name, List<String> packages) {
    int dotPos = name.lastIndexOf('.');
    if (dotPos != -1) {
      String packageName = name.substring(0, dotPos);
      packages.add(packageName);
      populateParentPackages(packageName, packages);
    } 
    return packages;
  }
}
