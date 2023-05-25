# 更新Demo模块配置信息，写入demo/conf.py文件

import os

if __name__ == '__main__':

    projectPath = str(os.path.realpath(__file__)).strip().replace('/script/update.py','').replace('\\','/')

    inputbuf2 = open(projectPath+'/engine/detection/include/ognl.tab.h','r',encoding='utf-8')
    outputbuf1 = open(projectPath+'/demo/conf.py','w',encoding='utf-8')

    tokenIndexDict = {}
    for line in inputbuf2:
        line = line.strip()
        if line.find('=')!=-1 and line.find('/*')!=-1:
            if line.find(',')==-1 : line = line.replace("/*",",/*")
            tokenInfo = line.split(",")[0].replace(" ","").split("=")
            keyword, num = tokenInfo[0], tokenInfo[1]
            tokenIndexDict.update( {int(num):str(keyword)} )

    outputbuf1.write("# 配置文件"+'\n')
    outputbuf1.write("# 运行项目所需的全局变量定义在此文件"+'\n')
    outputbuf1.write("# 该文件由script/update.py生成"+'\n')
    outputbuf1.write('\n')
    outputbuf1.write("import ctypes" + '\n')
    outputbuf1.write("from ctypes import *"+'\n')
    outputbuf1.write("from ctypes import cdll"+'\n')
    outputbuf1.write('\n')
    outputbuf1.write("# 通过CDLL方法调用C代码的可执行文件，C代码位于engine文件夹下"+'\n')
    outputbuf1.write("class parserStruct(Structure):"+'\n')
    outputbuf1.write("    _fields_ = [(\"input_len\",c_int),(\"full_token_list\",POINTER(c_int))]"+'\n')
    outputbuf1.write("detectionEngine = cdll.LoadLibrary(\"./engine/detection.so\")" + '\n')
    outputbuf1.write("detectionEngine.lexer.restype = ctypes.POINTER(parserStruct)"+'\n')
    outputbuf1.write('\n')
    outputbuf1.write("# Token号与Token名的对应关系，主要用于词法分析，从engine/detection/include/ognl.tab.h文件生成"+'\n')
    outputbuf1.write("tokenDict = "+str(tokenIndexDict)+'\n')
    outputbuf1.write('\n')

    inputbuf2.close()
    outputbuf1.close()
