from demo.detection import *
from demo.debug import *

if __name__ == '__main__':

    sentence = open("data/input.txt","r",encoding="utf-8").readline().strip() # 输入语句，data/input.txt
    # print(lexerTest(lexerEngine(sentence)))
    # print(reDetection(sentence))
    print(detectionTest(sentence))
    # 1:dataset(345)  0:authority_data(72)   
    # detectFile(1)
