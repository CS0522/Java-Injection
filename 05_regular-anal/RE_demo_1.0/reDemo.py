import re

# 模式匹配文件的相对路径
patternFilePath = "05_regular-anal/RE_demo_1.0/data/pattern.txt"
# dataset 文件的相对路径
datasetPath = "05_regular-anal/RE_demo_1.0/data/dataset_345.txt"
# output 文件的相对路径
outputFilePath = "05_regular-anal/RE_demo_1.0/data/output.txt"

# function
"""
flag:
1: injection
0: noninjection
"""
def reDec(sentence):
    try:
        patternFile = open(patternFilePath, 'r', encoding='utf-8')
        patternLines = patternFile.readlines()

        flag = False

        for i in range(0, len(patternLines)):
            # delete head and tail whitespace
            pattern = str(patternLines[i]).strip()
            # get the result of matching
            result = str(re.search(pattern, sentence, flags=re.I))   # flags = re.I, 忽略大小写
            # if matches, set flag as 'True', and break out
            if(result != "None"):
                flag = True

                print("match row " + str(i + 1) + " in pattern file")
                print("当前 pattern: " + pattern)
                
                break
        
        return flag
    
    except FileNotFoundError as e:
        print("Open pattern file error: ")
        print(e)

    finally:
        # close 
        patternFile.close()


if __name__ == '__main__':
    try:
        # open dataset
        datasetFile = open(datasetPath, "r", encoding='utf-8')
        datasetLines = datasetFile.readlines()
        # open / create output file
        outputFile = open(outputFilePath, "w+", encoding='utf-8')

        # traverse the data in dataset
        for i in range(0, len(datasetLines)):
            # delete head and tail whitespace
            sentence = str(datasetLines[i]).strip()
            
            print()
            print("第 " + str(i + 1) + " 行语句: ")
            print("当前 sentence: " + sentence)
            
            # matches, then write to output file
            if (reDec(sentence) == True):
                outputFile.write(datasetLines[i])

    except FileNotFoundError as e:
        print("Open dataset file or output file error: ")
        print(e)
    
    finally:
        # close all
        datasetFile.close()
        outputFile.close()