from demo.detection import *
from demo.debug import *

if __name__ == '__main__':

    sentence = open("data/input.txt","r",encoding="utf-8").readline().strip() # 输入语句，data/input.txt
    print("lexer :" , lexerTest(lexerEngine(sentence)))

    print(detection(sentence))

    # detectFile("temp")
    # detectCmdchop()
