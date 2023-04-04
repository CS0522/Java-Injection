// package .home.frank.Workspace.Java-Security.s2-048;

import java.lang.reflect.AccessibleObject;
import java.lang.reflect.Member;
import java.lang.reflect.Modifier;
import java.util.Map;
import ognl.MemberAccess;

public class DefaultMemberAccess implements MemberAccess {
  public boolean allowPrivateAccess = false;
  
  public boolean allowProtectedAccess = false;
  
  public boolean allowPackageProtectedAccess = false;
  
  public DefaultMemberAccess(boolean allowAllAccess) {
    this(allowAllAccess, allowAllAccess, allowAllAccess);
  }
  
  public DefaultMemberAccess(boolean allowPrivateAccess, boolean allowProtectedAccess, boolean allowPackageProtectedAccess) {
    this.allowPrivateAccess = allowPrivateAccess;
    this.allowProtectedAccess = allowProtectedAccess;
    this.allowPackageProtectedAccess = allowPackageProtectedAccess;
  }
  
  public boolean getAllowPrivateAccess() {
    return this.allowPrivateAccess;
  }
  
  public void setAllowPrivateAccess(boolean value) {
    this.allowPrivateAccess = value;
  }
  
  public boolean getAllowProtectedAccess() {
    return this.allowProtectedAccess;
  }
  
  public void setAllowProtectedAccess(boolean value) {
    this.allowProtectedAccess = value;
  }
  
  public boolean getAllowPackageProtectedAccess() {
    return this.allowPackageProtectedAccess;
  }
  
  public void setAllowPackageProtectedAccess(boolean value) {
    this.allowPackageProtectedAccess = value;
  }
  
  public Object setup(Map context, Object target, Member member, String propertyName) {
    Object result = null;
    if (isAccessible(context, target, member, propertyName)) {
      AccessibleObject accessible = (AccessibleObject)member;
      if (!accessible.isAccessible()) {
        result = Boolean.TRUE;
        accessible.setAccessible(true);
      } 
    } 
    return result;
  }
  
  public void restore(Map context, Object target, Member member, String propertyName, Object state) {
    if (state != null)
      ((AccessibleObject)member).setAccessible(((Boolean)state).booleanValue()); 
  }
  
  public boolean isAccessible(Map context, Object target, Member member, String propertyName) {
    int modifiers = member.getModifiers();
    boolean result = Modifier.isPublic(modifiers);
    if (!result)
      if (Modifier.isPrivate(modifiers)) {
        result = getAllowPrivateAccess();
      } else if (Modifier.isProtected(modifiers)) {
        result = getAllowProtectedAccess();
      } else {
        result = getAllowPackageProtectedAccess();
      }  
    return result;
  }
}
