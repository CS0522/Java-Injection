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


# 对语句的预处理
def preprocess( sentence:str ):
    sentence = urlDecode(sentence).strip()
    sentence = htmlDecode(sentence).strip()
    return sentence

# 完整检测流程
def detection( sentence:str ):

    sentence = preprocess(sentence)
    if syntaxDetecion(sentence)=="INJECTION" : return "INJECTION"
    else : return "NORMAL"
    
