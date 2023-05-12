import re

def detection( sentence ):
    inputbuf = open("05_regular-anal/RE_demo_1.0/data/ognl.txt",'r',encoding='utf-8')
    lines = inputbuf.readlines()
    result = "NORMAL"
    for i in range(0,len(lines)):
        target = str(lines[i]).strip()
        # print(target)
        # print(re.search(target, sentence))
        if( str(re.search(target, sentence)) != "None" ):
            result = "JAVA_INJECTION"
            print(re.search(target, sentence).group())
            break
    return result


if __name__ == '__main__':
    # sentence = "#f=#context.get(a),#f.getWriter()java.lang.Runtime@getRuntime()" 
    #f=#context.get(a),#f.getWriter()
    sentence = "java.lang.System" 
    print(sentence)
    print(detection(sentence))


    # print(re.search("java.lang.Runtime",sentence))