# 通过CDLL方法调用C代码，包括词法解析、短串语法解析、长串语法解析和语义分析

from demo.conf import *

def lexerEngine( sentence:str ):
    parserRes = detectionEngine.lexer(bytes(sentence,encoding="utf-8"))
    inputLen = parserRes.contents.input_len
    tokenList = []
    for i in range(0,inputLen) :
        tokenList.append(int(parserRes.contents.full_token_list[i]))
    detectionEngine.freeAll(parserRes)
    return tokenList

def syntaxDetecion( sentence:str ):
    res = detectionEngine.detection(bytes(sentence,encoding="utf-8"))
    if res == 0 : return "INJECTION"
    return "NORMAL"
