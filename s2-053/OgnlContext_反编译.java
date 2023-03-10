// package .home.frank.Workspace.Java-Security.s2-053;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import ognl.ClassResolver;
import ognl.DefaultClassResolver;
import ognl.DefaultMemberAccess;
import ognl.DefaultTypeConverter;
import ognl.Evaluation;
import ognl.MemberAccess;
import ognl.Node;
import ognl.OgnlOps;
import ognl.OgnlRuntime;
import ognl.TypeConverter;
import ognl.enhance.LocalReference;

public class OgnlContext implements Map {
  public static final String CONTEXT_CONTEXT_KEY = "context";
  
  public static final String ROOT_CONTEXT_KEY = "root";
  
  public static final String THIS_CONTEXT_KEY = "this";
  
  public static final String TRACE_EVALUATIONS_CONTEXT_KEY = "_traceEvaluations";
  
  public static final String LAST_EVALUATION_CONTEXT_KEY = "_lastEvaluation";
  
  public static final String KEEP_LAST_EVALUATION_CONTEXT_KEY = "_keepLastEvaluation";
  
  public static final String CLASS_RESOLVER_CONTEXT_KEY = "_classResolver";
  
  public static final String TYPE_CONVERTER_CONTEXT_KEY = "_typeConverter";
  
  public static final String MEMBER_ACCESS_CONTEXT_KEY = "_memberAccess";
  
  private static final String PROPERTY_KEY_PREFIX = "ognl";
  
  private static boolean DEFAULT_TRACE_EVALUATIONS = false;
  
  private static boolean DEFAULT_KEEP_LAST_EVALUATION = false;
  
  public static final ClassResolver DEFAULT_CLASS_RESOLVER = (ClassResolver)new DefaultClassResolver();
  
  public static final TypeConverter DEFAULT_TYPE_CONVERTER = (TypeConverter)new DefaultTypeConverter();
  
  public static final MemberAccess DEFAULT_MEMBER_ACCESS = (MemberAccess)new DefaultMemberAccess(false);
  
  private static Map RESERVED_KEYS = new HashMap<Object, Object>(11);
  
  private Object _root;
  
  private Object _currentObject;
  
  private Node _currentNode;
  
  private boolean _traceEvaluations = DEFAULT_TRACE_EVALUATIONS;
  
  private Evaluation _rootEvaluation;
  
  private Evaluation _currentEvaluation;
  
  private Evaluation _lastEvaluation;
  
  private boolean _keepLastEvaluation = DEFAULT_KEEP_LAST_EVALUATION;
  
  private final Map _values;
  
  private ClassResolver _classResolver = DEFAULT_CLASS_RESOLVER;
  
  private TypeConverter _typeConverter = DEFAULT_TYPE_CONVERTER;
  
  private MemberAccess _memberAccess = DEFAULT_MEMBER_ACCESS;
  
  static {
    RESERVED_KEYS.put("context", null);
    RESERVED_KEYS.put("root", null);
    RESERVED_KEYS.put("this", null);
    RESERVED_KEYS.put("_traceEvaluations", null);
    RESERVED_KEYS.put("_lastEvaluation", null);
    RESERVED_KEYS.put("_keepLastEvaluation", null);
    RESERVED_KEYS.put("_classResolver", null);
    RESERVED_KEYS.put("_typeConverter", null);
    RESERVED_KEYS.put("_memberAccess", null);
    try {
      String s;
      if ((s = System.getProperty("ognl.traceEvaluations")) != null)
        DEFAULT_TRACE_EVALUATIONS = Boolean.valueOf(s.trim()).booleanValue(); 
      if ((s = System.getProperty("ognl.keepLastEvaluation")) != null)
        DEFAULT_KEEP_LAST_EVALUATION = Boolean.valueOf(s.trim()).booleanValue(); 
    } catch (SecurityException ex) {}
  }
  
  private final List _typeStack = new ArrayList(3);
  
  private final List _accessorStack = new ArrayList(3);
  
  private int _localReferenceCounter = 0;
  
  private Map _localReferenceMap = null;
  
  public OgnlContext() {
    this(null, null, null);
  }
  
  public OgnlContext(ClassResolver classResolver, TypeConverter typeConverter, MemberAccess memberAccess) {
    this(classResolver, typeConverter, memberAccess, new HashMap<Object, Object>(23));
  }
  
  public OgnlContext(Map values) {
    this(null, null, null, values);
  }
  
  public OgnlContext(ClassResolver classResolver, TypeConverter typeConverter, MemberAccess memberAccess, Map values) {
    this._values = values;
    if (classResolver != null)
      this._classResolver = classResolver; 
    if (typeConverter != null)
      this._typeConverter = typeConverter; 
    if (memberAccess != null)
      this._memberAccess = memberAccess; 
  }
  
  public void setValues(Map value) {
    for (Iterator it = value.keySet().iterator(); it.hasNext(); ) {
      Object k = it.next();
      this._values.put(k, value.get(k));
    } 
  }
  
  public Map getValues() {
    return this._values;
  }
  
  public void setClassResolver(ClassResolver value) {
    if (value == null)
      throw new IllegalArgumentException("cannot set ClassResolver to null"); 
    this._classResolver = value;
  }
  
  public ClassResolver getClassResolver() {
    return this._classResolver;
  }
  
  public void setTypeConverter(TypeConverter value) {
    if (value == null)
      throw new IllegalArgumentException("cannot set TypeConverter to null"); 
    this._typeConverter = value;
  }
  
  public TypeConverter getTypeConverter() {
    return this._typeConverter;
  }
  
  public void setMemberAccess(MemberAccess value) {
    if (value == null)
      throw new IllegalArgumentException("cannot set MemberAccess to null"); 
    this._memberAccess = value;
  }
  
  public MemberAccess getMemberAccess() {
    return this._memberAccess;
  }
  
  public void setRoot(Object value) {
    this._root = value;
    this._accessorStack.clear();
    this._typeStack.clear();
    this._currentObject = value;
    if (this._currentObject != null)
      setCurrentType(this._currentObject.getClass()); 
  }
  
  public Object getRoot() {
    return this._root;
  }
  
  public boolean getTraceEvaluations() {
    return this._traceEvaluations;
  }
  
  public void setTraceEvaluations(boolean value) {
    this._traceEvaluations = value;
  }
  
  public Evaluation getLastEvaluation() {
    return this._lastEvaluation;
  }
  
  public void setLastEvaluation(Evaluation value) {
    this._lastEvaluation = value;
  }
  
  public void recycleLastEvaluation() {
    OgnlRuntime.getEvaluationPool().recycleAll(this._lastEvaluation);
    this._lastEvaluation = null;
  }
  
  public boolean getKeepLastEvaluation() {
    return this._keepLastEvaluation;
  }
  
  public void setKeepLastEvaluation(boolean value) {
    this._keepLastEvaluation = value;
  }
  
  public void setCurrentObject(Object value) {
    this._currentObject = value;
  }
  
  public Object getCurrentObject() {
    return this._currentObject;
  }
  
  public void setCurrentAccessor(Class<?> type) {
    this._accessorStack.add(type);
  }
  
  public Class getCurrentAccessor() {
    if (this._accessorStack.isEmpty())
      return null; 
    return this._accessorStack.get(this._accessorStack.size() - 1);
  }
  
  public Class getPreviousAccessor() {
    if (this._accessorStack.isEmpty())
      return null; 
    if (this._accessorStack.size() > 1)
      return this._accessorStack.get(this._accessorStack.size() - 2); 
    return null;
  }
  
  public Class getFirstAccessor() {
    if (this._accessorStack.isEmpty())
      return null; 
    return this._accessorStack.get(0);
  }
  
  public Class getCurrentType() {
    if (this._typeStack.isEmpty())
      return null; 
    return this._typeStack.get(this._typeStack.size() - 1);
  }
  
  public void setCurrentType(Class<?> type) {
    this._typeStack.add(type);
  }
  
  public Class getPreviousType() {
    if (this._typeStack.isEmpty())
      return null; 
    if (this._typeStack.size() > 1)
      return this._typeStack.get(this._typeStack.size() - 2); 
    return null;
  }
  
  public void setPreviousType(Class<?> type) {
    if (this._typeStack.isEmpty() || this._typeStack.size() < 2)
      return; 
    this._typeStack.set(this._typeStack.size() - 2, type);
  }
  
  public Class getFirstType() {
    if (this._typeStack.isEmpty())
      return null; 
    return this._typeStack.get(0);
  }
  
  public void setCurrentNode(Node value) {
    this._currentNode = value;
  }
  
  public Node getCurrentNode() {
    return this._currentNode;
  }
  
  public Evaluation getCurrentEvaluation() {
    return this._currentEvaluation;
  }
  
  public void setCurrentEvaluation(Evaluation value) {
    this._currentEvaluation = value;
  }
  
  public Evaluation getRootEvaluation() {
    return this._rootEvaluation;
  }
  
  public void setRootEvaluation(Evaluation value) {
    this._rootEvaluation = value;
  }
  
  public Evaluation getEvaluation(int relativeIndex) {
    Evaluation result = null;
    if (relativeIndex <= 0) {
      result = this._currentEvaluation;
      while (++relativeIndex < 0 && result != null)
        result = result.getParent(); 
    } 
    return result;
  }
  
  public void pushEvaluation(Evaluation value) {
    if (this._currentEvaluation != null) {
      this._currentEvaluation.addChild(value);
    } else {
      setRootEvaluation(value);
    } 
    setCurrentEvaluation(value);
  }
  
  public Evaluation popEvaluation() {
    Evaluation result = this._currentEvaluation;
    setCurrentEvaluation(result.getParent());
    if (this._currentEvaluation == null) {
      setLastEvaluation(getKeepLastEvaluation() ? result : null);
      setRootEvaluation(null);
      setCurrentNode(null);
    } 
    return result;
  }
  
  public int incrementLocalReferenceCounter() {
    return ++this._localReferenceCounter;
  }
  
  public void addLocalReference(String key, LocalReference reference) {
    if (this._localReferenceMap == null)
      this._localReferenceMap = new LinkedHashMap<Object, Object>(); 
    this._localReferenceMap.put(key, reference);
  }
  
  public Map getLocalReferences() {
    return this._localReferenceMap;
  }
  
  public int size() {
    return this._values.size();
  }
  
  public boolean isEmpty() {
    return this._values.isEmpty();
  }
  
  public boolean containsKey(Object key) {
    return this._values.containsKey(key);
  }
  
  public boolean containsValue(Object value) {
    return this._values.containsValue(value);
  }
  
  public Object get(Object key) {
    Object result;
    if (RESERVED_KEYS.containsKey(key)) {
      if (key.equals("this")) {
        result = getCurrentObject();
      } else if (key.equals("root")) {
        result = getRoot();
      } else if (key.equals("context")) {
        result = this;
      } else if (key.equals("_traceEvaluations")) {
        result = getTraceEvaluations() ? Boolean.TRUE : Boolean.FALSE;
      } else if (key.equals("_lastEvaluation")) {
        result = getLastEvaluation();
      } else if (key.equals("_keepLastEvaluation")) {
        result = getKeepLastEvaluation() ? Boolean.TRUE : Boolean.FALSE;
      } else if (key.equals("_classResolver")) {
        result = getClassResolver();
      } else if (key.equals("_typeConverter")) {
        result = getTypeConverter();
      } else if (key.equals("_memberAccess")) {
        result = getMemberAccess();
      } else {
        throw new IllegalArgumentException("unknown reserved key '" + key + "'");
      } 
    } else {
      result = this._values.get(key);
    } 
    return result;
  }
  
  public Object put(Object key, Object value) {
    Object result;
    if (RESERVED_KEYS.containsKey(key)) {
      if (key.equals("this")) {
        result = getCurrentObject();
        setCurrentObject(value);
      } else if (key.equals("root")) {
        result = getRoot();
        setRoot(value);
      } else {
        if (key.equals("context"))
          throw new IllegalArgumentException("can't change context in context"); 
        if (key.equals("_traceEvaluations")) {
          result = getTraceEvaluations() ? Boolean.TRUE : Boolean.FALSE;
          setTraceEvaluations(OgnlOps.booleanValue(value));
        } else if (key.equals("_lastEvaluation")) {
          result = getLastEvaluation();
          this._lastEvaluation = (Evaluation)value;
        } else if (key.equals("_keepLastEvaluation")) {
          result = getKeepLastEvaluation() ? Boolean.TRUE : Boolean.FALSE;
          setKeepLastEvaluation(OgnlOps.booleanValue(value));
        } else if (key.equals("_classResolver")) {
          result = getClassResolver();
          setClassResolver((ClassResolver)value);
        } else if (key.equals("_typeConverter")) {
          result = getTypeConverter();
          setTypeConverter((TypeConverter)value);
        } else if (key.equals("_memberAccess")) {
          result = getMemberAccess();
          setMemberAccess((MemberAccess)value);
        } else {
          throw new IllegalArgumentException("unknown reserved key '" + key + "'");
        } 
      } 
    } else {
      result = this._values.put(key, value);
    } 
    return result;
  }
  
  public Object remove(Object key) {
    Object result;
    if (RESERVED_KEYS.containsKey(key)) {
      if (key.equals("this")) {
        result = getCurrentObject();
        setCurrentObject(null);
      } else if (key.equals("root")) {
        result = getRoot();
        setRoot(null);
      } else {
        if (key.equals("context"))
          throw new IllegalArgumentException("can't remove context from context"); 
        if (key.equals("_traceEvaluations"))
          throw new IllegalArgumentException("can't remove _traceEvaluations from context"); 
        if (key.equals("_lastEvaluation")) {
          result = this._lastEvaluation;
          setLastEvaluation(null);
        } else {
          if (key.equals("_keepLastEvaluation"))
            throw new IllegalArgumentException("can't remove _keepLastEvaluation from context"); 
          if (key.equals("_classResolver")) {
            result = getClassResolver();
            setClassResolver(null);
          } else if (key.equals("_typeConverter")) {
            result = getTypeConverter();
            setTypeConverter(null);
          } else if (key.equals("_memberAccess")) {
            result = getMemberAccess();
            setMemberAccess(null);
          } else {
            throw new IllegalArgumentException("unknown reserved key '" + key + "'");
          } 
        } 
      } 
    } else {
      result = this._values.remove(key);
    } 
    return result;
  }
  
  public void putAll(Map t) {
    for (Iterator it = t.keySet().iterator(); it.hasNext(); ) {
      Object k = it.next();
      put(k, t.get(k));
    } 
  }
  
  public void clear() {
    this._values.clear();
    this._typeStack.clear();
    this._accessorStack.clear();
    this._localReferenceCounter = 0;
    if (this._localReferenceMap != null)
      this._localReferenceMap.clear(); 
    setRoot(null);
    setCurrentObject(null);
    setRootEvaluation(null);
    setCurrentEvaluation(null);
    setLastEvaluation(null);
    setCurrentNode(null);
    setClassResolver(DEFAULT_CLASS_RESOLVER);
    setTypeConverter(DEFAULT_TYPE_CONVERTER);
    setMemberAccess(DEFAULT_MEMBER_ACCESS);
  }
  
  public Set keySet() {
    return this._values.keySet();
  }
  
  public Collection values() {
    return this._values.values();
  }
  
  public Set entrySet() {
    return this._values.entrySet();
  }
  
  public boolean equals(Object o) {
    return this._values.equals(o);
  }
  
  public int hashCode() {
    return this._values.hashCode();
  }
}
