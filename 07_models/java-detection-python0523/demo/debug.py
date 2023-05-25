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

def reDetectionTest(sentence):
    print("-"*40)
    print("* [INPUT] ",sentence)
    try:
        patternFile = open("data/ognl.txt", 'r', encoding='utf-8')
        patternLines = patternFile.readlines()
        flag = False
        for i in range(0, len(patternLines)):
            pattern = str(patternLines[i]).strip()
            result = str(re.search(pattern, sentence, flags=re.I))  
            if(result != "None"):
                flag = True
                print("* [RE_DEC RES] INJECTION")
                print("* [PATTERN] " + pattern)
                break
        return flag
    except FileNotFoundError as e:
        print("[OPEN PATTERN FILE ERROR]")
        print(e)
    finally:
        patternFile.close()


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
    print("[INPUT] ",sentence)
    sentence = preprocess(sentence)
    print("[PREPROCESS] ",sentence)
    print("[TOKEN]",lexerTest(lexerEngine(sentence)))
    sentence = preprocess(sentence)
    # 开启 re 正则匹配和 语法分析
    if reDetectionTest(sentence)==True : return "RE_INJECTION"
    if syntaxDetecionTest(sentence)=="INJECTION" : return "SYNTAX_INJECTION"
    return "NORMAL"


