# 配置文件
# 运行项目所需的全局变量定义在此文件
# 该文件由script/update.py生成

import ctypes
from ctypes import *
from ctypes import cdll

# 通过CDLL方法调用C代码的可执行文件，C代码位于engine文件夹下
class parserStruct(Structure):
    _fields_ = [("input_len",c_int),("full_token_list",POINTER(c_int))]
detectionEngine = cdll.LoadLibrary("./engine/detection.so")
detectionEngine.lexer.restype = ctypes.POINTER(parserStruct)

# Token号与Token名的对应关系，主要用于词法分析，从engine/detection/include/ognl.tab.h文件生成
tokenDict = {0: 'YYEOF', 256: 'YYerror', 257: 'YYUNDEF', 258: 'AND', 259: 'BUFFEREDREADER', 260: 'CLASS', 261: 'CLASSLOADER', 262: 'COLLECTIONS', 263: 'COMPILER', 264: 'DATAINPUTSTREAM', 265: 'DEFAULT_MEMBER_ACCESS', 266: 'ENTITYMANAGER', 267: 'FILE_P', 268: 'FILEDESCRIPTOR', 269: 'FILEINPUTSTREAM', 270: 'FILEOUTPUTSTREAM', 271: 'FILEPERMISSION', 272: 'FILEREADER', 273: 'FILEWRITER', 274: 'INHERITABLETHREADLOCAL', 275: 'IO', 276: 'JAVA', 277: 'JAVAX', 278: 'LANG', 279: 'MEMBERACCESS', 280: 'MISC', 281: 'NEW', 282: 'NOT', 283: 'OBJECT', 284: 'OGNL', 285: 'OGNLCONTEXT', 286: 'OR', 287: 'PACKAGE', 288: 'PERSISTENCE', 289: 'PROCESS', 290: 'PROCESSBUILDER', 291: 'RUNTIME', 292: 'RUNTIMEPERMISSION', 293: 'SCANNER', 294: 'SCRIPT', 295: 'SCRIPTENGINEMANAGE', 296: 'SECURITYMANAGER', 297: 'SERVLET', 298: 'SERVLETCONTEXT', 299: 'SHUTDOWN', 300: 'SUN', 301: 'SYSTEM', 302: 'THREAD', 303: 'THREADGROUP', 304: 'THREADLOCAL', 305: 'UNSAFE', 306: 'UTIL', 307: 'XOR', 308: 'EXPRESSION_START', 309: 'EXPRESSION_END', 310: 'DOT_DOT', 311: 'NOT_EQUAL', 312: 'EQUAL', 313: 'LESS_EQUAL', 314: 'GREATER_EQUAL', 315: 'AND_AND', 316: 'OR_OR', 317: 'ICONST', 318: 'BCONST', 319: 'XCONST', 320: 'SCONST', 321: 'USCONST', 322: 'FCONST', 323: 'IDENT', 324: 'UIDENT'}

