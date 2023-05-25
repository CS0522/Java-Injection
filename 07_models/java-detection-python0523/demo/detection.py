from demo.engine import *


# URL解码
def urlDecode( sentence:str ):
    from urllib import parse
    sentenceTmp = parse.unquote(sentence)
    if sentence.count("+") < sentenceTmp.count("+") :
        sentenceTmp = parse.unquote(sentence.replace("+"," "))
    sentence = sentenceTmp
    return sentence

# HTML解码
def htmlDecode( sentence:str ):
    from html import unescape  # python 3.4+
    from html.parser import HTMLParser  # python 3.x (<3.4)
    unescape = HTMLParser().unescape
    return unescape(sentence)

# Unicode解码

# 对语句的预处理
def preprocess( sentence:str ):
    sentence = urlDecode(sentence).strip()
    sentence = htmlDecode(sentence).strip()
    return sentence

# Hyperscan
def hyperscan( sentence:str ):
    with open("data/config.txt",'r') as f:
        list = f.readlines()
        for num,i in enumerate(list):
            list[num] = i[:-1]
        hyperscanPattern = re.compile('|'.join(list), re.I)
        if re.search(hyperscanPattern, sentence)==None :return False
        else :return True

# re正则匹配
def reDetection(sentence):
    patternFile = open("data/ognl.txt", 'r', encoding='utf-8')
    patternLines = patternFile.readlines()
    flag = False
    for i in range(0, len(patternLines)):
        pattern = str(patternLines[i]).strip()
        result = str(re.search(pattern, sentence, flags=re.I))
        if(result != "None"):
            flag = True  
            break
    return flag
    patternFile.close()

# 完整检测流程
def detection( sentence:str ):
    sentence = preprocess(sentence)
    if reDetection(sentence)==True : return "RE_INJECTION"
    if syntaxDetecion(sentence)=="INJECTION" : return "INJECTION"
    else : return "NORMAL"
    
# 检测文件
def detectFile( pattern:int ):
    if pattern== 1 :
        inputbuf = open("data/data.txt","r",encoding="utf-8")
    else : inputbuf = open("data/authority_data.txt","r",encoding="utf-8")
    # inputbuf = open("data/authority_data.txt","r",encoding="utf-8")
    # inputbuf = open("data/data_orignl.txt","r",encoding="utf-8")
    outputbufInj = open("data/INJECTION.txt",'w',encoding='utf-8')
    outputbufNor = open("data/NORMAL.txt",'w',encoding='utf-8')
    counterInj,counterNor = 0,0

    for line in inputbuf:
        line = line.strip()
        print(line)
        res = detection(line)
        print(res)
        if res=="INJECTION" or res== "RE_INJECTION" :
            outputbufInj.write(line+'\n')
            counterInj += 1
        else:
            outputbufNor.write(line+'\n')
            counterNor += 1
    print("[{}] Inj: {}, Nor: {}".format(inputbuf,counterInj,counterNor))
    inputbuf.close()
    outputbufInj.close()
    outputbufNor.close()
