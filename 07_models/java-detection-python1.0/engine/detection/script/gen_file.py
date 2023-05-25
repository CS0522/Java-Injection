import os
import argparse

def modifyTabC():
    inputbuf = open("ognl.tab.c",'r',encoding="utf-8")
    lines = inputbuf.readlines()
    inputbuf.close()
    outputbuf = open("ognl.tab.c",'w',encoding="utf-8")
    for line in lines:
        line = line.replace("ognl.tab.h","../include/ognl.tab.h")
        line = line.replace("grammar/ognl.y","../grammar/ognl.y")
        outputbuf.write(line)
        # if line.find("Now at end of input")!=-1:
        #     outputbuf.write("      YYACCEPT;")
    outputbuf.close()

def modifySqlC():
    inputbuf = open("ognl.c",'r',encoding="utf-8")
    lines = inputbuf.readlines()
    inputbuf.close()
    outputbuf = open("ognl.c",'w',encoding="utf-8")
    for line in lines:
        line = line.replace("grammar/ognl.l","../grammar/ognl.l")
        if line.find("at end of input")!=-1:
            line = "/*" + line + "*/"
        outputbuf.write(line)

def modifyTabH():
    inputbuf = open("ognl.tab.h",'r',encoding="utf-8")
    lines = inputbuf.readlines()
    inputbuf.close()
    outputbuf = open("ognl.tab.h",'w',encoding="utf-8")
    for line in lines:
        outputbuf.write(line)
    outputbuf.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', type=str, help='Path to the file name.')
    args, unparsed = parser.parse_known_args()
    filename = args.input
    filename = filename.strip()
    # print("filename = " , filename[-1])
    if filename == "ognl.tab.c" : modifyTabC()
    elif filename == "ognl.tab.h" : modifyTabH()
    elif filename == "ognl.c" : modifySqlC()
    else : print("Wrong input.")
