# Java.io

## Java.io 总述

* java.io 包中的类非常繁多，但其实只要归成 4 类：`InputStream` & `OutputStream`、`Reader` & `Writer`

* 横向归类：InputStream & OutputStream（字节流）、Reader & Writer（字符流）
* 纵向归类：InputStream 作为父类


### 装饰者模式

* 装饰者模式就是在一个主体（被装饰者）的外部使用装饰类来进行装饰，对主体的行为根据不同的装饰者类进行不同的修改。单个的装饰类自根据自身特点对主体的行为进行部分改进，因此可以组合多个装饰类来对主体进行修改（在代码中表现为多层装饰类的嵌套）。  
 
  ![](https://static.oschina.net/uploads/img/201511/16224138_02hJ.png)

### 结论
* 处理非文本数据使用字节流
* 处理具体的文本数据使用字符流
* 例如对于文件复制这样的操作来说，即使是文本文件的复制，我们对其具体的内容是什么并不关心，因此可以直接使用字节流。但当我们要从一个文本文件中读取内容，我们关心其具体的内容，所以使用字符流



## Java.io API
[IO - 菜鸟教程](https://www.runoob.com/java/java-files-io.html)

![](https://static.oschina.net/uploads/img/201511/16224306_jZH8.png)  

![](https://www.runoob.com/wp-content/uploads/2013/12/iostream2xx.png)

### 字节流

#### OutputStream
* ByteArrayOutputSteam：将数据输出到字节数组（byte array）中，也就是内存，不用生成文件；
* FileOutputStream：将数据输出到具体的文件；
* PipedOutputStream：将数据输出到线程，即通过与 PipedInputStream 联合使用，将数据在不同的线程之间传递；
* FilterOutputStream：装饰类的父类
  * BufferedOutputStream：使用了缓冲区，调用 flush() 才会清空缓冲区将数据写入文件。与普通 OutputStream 相比，由于不用频繁地与文件进行 I/O 数据传输（内存与磁盘之间，这将消耗大部分性能），而是在每次调用 flush() 时一次性地将一块数据在内存与磁盘中传输，因此会性能将得到提升（有 NIO 的影子）；
  * DataOutputStream：用于方便地传输基础类型的数据，因此除了传统的 write() 外，还有一堆 writeInt()、writeDouble()、writeBoolean() 等；
  * PrintStream：InputStream 本来是适合用于非文本的二进制文件（如图片、声音文件等），而 PrintStream 则是在字节流中专门用于打印文本内容；

#### InputStream
* ByteArrayInputStream：从内存中读取数据；
* FileInputStream：从文件中读取数据；
* PipedInputStream：从一个线程中读取数据，从另一个线程中输出 (PipedOutputStream)，同一线程下使用者两个对象可能会造成线程死锁；
* SequenceInputStream：将两个 InputStream 合并成一个；
* FilterInputStream：装饰类的父类；
  * BufferedInputStream：使用了缓冲区，参考 BufferedOutputStream；
  * DataInputStream：方便地读取基本类型的数据，因此除了基础的 read() 外，还有一堆 readChar()、readDouble()、readInt() 等；


### 字符流

#### Writer
* BufferedWriter：缓冲区；
* CharArrayWriter：面向内存；
* PipedWriter：面向线程；
* PrintWriter：方便输出，特别是按格式输出 printf ()；
* StringWriter：使用 StringBuilder 来存放内容；
* OutputStreamWriter：用于字符流与字节流之间的转换；
* FileWriter：面向文件
* FilterWriter：装饰类

#### Reader
* BufferedReader：缓冲区；
* CharArrayReader：面向内存；
* PipedReader：面向线程；
* InputStreamReader：用于字符流与字节流之间的转换；
* FileReader：面向文件
* FilterReader