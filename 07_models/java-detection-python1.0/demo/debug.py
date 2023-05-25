from demo.conf import *
from demo.engine import *
from demo.detection import *

# 词法解析，输出的是Token名
def lexerTest( tokenList ):
    tokenNameList = []
    for i in range(0,len(tokenList)) :
        token = tokenList[i]
        if token >= 256 : tokenName = tokenDict[token]
        else : tokenName = chr(token)
        tokenNameList.append(tokenName)
    tokenListInfo = ""
    for i in tokenNameList : tokenListInfo = tokenListInfo + str(i) + " "
    return tokenListInfo.strip()

def syntaxDetecionTest( sentence:str ):
    print("-"*40)
    print("* [INPUT] ",sentence)
    res = detectionEngine.detection(bytes(sentence,encoding="utf-8"))
    if res == 0 :
        print("*  [FULL DETEC RES] INJECTION")
        return "INJECTION"
    else :  
        print("* [FULL DETEC RES] NORMAL")
        return "NORMAL"

def detectionTest( sentence:str ):
    def detectionFull( sentence:str ):
        if syntaxDetecionTest(sentence)=="INJECTION" : return "INJECTION"
        else : return "NORMAL"
    print("[INPUT] ",sentence)
    sentence = preprocess(sentence)
    print("[PREPROCESS] ",sentence)
    print("[TOKEN]",lexerTest(lexerEngine(sentence)))
    sentence = preprocess(sentence)

    if syntaxDetecionTest(sentence)=="INJECTION" : return "INJECTION"
    else : return "NORMAL"

# 检测文件
def detectFile( filename:str ):
    import os
    import datetime
    inputbuf = open("data/"+filename+".txt","r",encoding="utf-8")
    folderName = filename.replace('/',"-")+"-"+str(datetime.datetime.now()).replace(':',"-").replace(' ',"-")
    os.mkdir("data/result/"+folderName)
    outputbufInj = open("data/result/"+folderName+"/INJECTION.txt",'w',encoding='utf-8')
    outputbufNor = open("data/result/"+folderName+"/NORMAL.txt",'w',encoding='utf-8')
    counterInj,counterNor = 0,0
    for line in inputbuf:
        line = line.strip()
        res = detection(line)
        if res=="INJECTION" :
            outputbufInj.write(line+'\n')
            counterInj += 1
        else:
            outputbufNor.write(line+'\n')
            counterNor += 1
    print("[{}] Inj: {}, Nor: {}".format(filename,counterInj,counterNor))
    inputbuf.close()
    outputbufInj.close()
    outputbufNor.close()

