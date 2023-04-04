<!-- Created by Frank -->
- [Java注入类汇总](#java注入类汇总)
  - [java.lang.ProcessBuilder](#javalangprocessbuilder)
  - [java.lang.RuntimePermission](#javalangruntimepermission)
  - [java.lang.ClassLoader](#javalangclassloader)
  - [java.lang.System](#javalangsystem)
  - [java.lang.ThreadGroup](#javalangthreadgroup)
  - [java.lang.Compiler](#javalangcompiler)
  - [java.lang.Thread](#javalangthread)
  - [java.lang.Class](#javalangclass)
  - [java.lang.ThreadLocal](#javalangthreadlocal)
  - [java.lang.Package](#javalangpackage)
  - [java.lang.Runtime](#javalangruntime)
  - [java.lang.SecurityManager](#javalangsecuritymanager)
  - [java.lang.Object](#javalangobject)
  - [java.lang.InheritableThreadLocal](#javalanginheritablethreadlocal)
  - [java.lang.Shutdown](#javalangshutdown)
  - [java.lang.Process](#javalangprocess)
  - [sun.misc.Unsafe](#sunmiscunsafe)
  - [java.io.File](#javaiofile)
  - [java.io.BufferedReader](#javaiobufferedreader)
  - [java.io.DataInputStream](#javaiodatainputstream)
  - [javax.script.ScriptEngineManager](#javaxscriptscriptenginemanager)
  - [javax.persistence.EntityManager](#javaxpersistenceentitymanager)
  - [javax.servlet.ServletContext](#javaxservletservletcontext)
  - [java.io.FileDescriptor](#javaiofiledescriptor)
  - [java.io.FileInputStream](#javaiofileinputstream)
  - [java.io.FileOutputStream](#javaiofileoutputstream)
  - [java.io.FilePermission](#javaiofilepermission)
  - [java.io.FileReader](#javaiofilereader)
  - [java.io.FileWriter](#javaiofilewriter)
  - [java.util.Collections](#javautilcollections)
  - [java.util.Scanner](#javautilscanner)

# Java注入类汇总

## java.lang.ProcessBuilder
## java.lang.RuntimePermission
## java.lang.ClassLoader
## java.lang.System
## java.lang.ThreadGroup
## java.lang.Compiler
## java.lang.Thread
## java.lang.Class
## java.lang.ThreadLocal
## java.lang.Package
## java.lang.Runtime
## java.lang.SecurityManager
## java.lang.Object
## java.lang.InheritableThreadLocal
## java.lang.Shutdown
## java.lang.Process
<!-- Frank -->
## sun.misc.Unsafe
* [cnblogs](https://www.cnblogs.com/barrywxx/p/10741701.html)
* allocateMemory(long)
* reallocateMemory(long, long)
* copyMemory(Object, long, Object, long, long)
* freeMemory(long)
* setMemory(Object, long, long, byte)
* getAndSetInt(Object, long, int)
* getAndSetObject(Object, long, Object)

## java.io.File
* createNewFile()
* createTempFile(String prefix, String suffix, File directory)
* delete()
* deleteOnExit()
* getCanonicalPath()
  * 抽象路径名 (与系统无关，根据系统加入不同分割符) 的规范路径名字符串
* isHidden()
* lastModified()
* list()
* listFiles()
* listRoots()
* setExecutable(boolean)
* setLastModified(long)
* setReadable(boolean readable, boolean ownerOnly)
* setWritable(boolean writable, boolean ownerOnly)

## java.io.BufferedReader
* read(char[] cbuf, int off, int len)
* readLine()

## java.io.DataInputStream
* read(byte[] b, int off, int len)
* readFully(byte[] b, int off, int len)
* readUTF()

## javax.script.ScriptEngineManager
* getEngineByExtension​(String extension)
* getEngineByName​(String shortName)
* getEngineFactories()
* registerEngineExtension​(String extension, ScriptEngineFactory factory)
* registerEngineName​(String name, ScriptEngineFactory factory)
* getBindings()
* setBindings​(Bindings bindings)

## javax.persistence.EntityManager
* [ObjectDB](https://www.objectdb.com/api/java/jpa/EntityManager)
* createNamedQuery(String name)
* createNativeQuery(String sqlString)
* createQuery(String qlString)
* getTransaction()
* merge(Object entity)
* persist(Object entity)
* remove(Object entity)
* unwrap(Class<T> cls)

## javax.servlet.ServletContext
* [biancheng](http://c.biancheng.net/servlet2/servletcontext.html)
* setAttribute(String name, Object obj)
* getAttribute(String name)
* removeAttribute(String name)
* getInitParameter(String name)
* getInitParameterNames()
* getResourcePaths(String path)
* getRealPath(String path) 
* getResourceAsStream(String path)

<!-- 后面的先不弄 -->
## java.io.FileDescriptor
## java.io.FileInputStream
## java.io.FileOutputStream
## java.io.FilePermission
## java.io.FileReader 
## java.io.FileWriter
## java.util.Collections
## java.util.Scanner