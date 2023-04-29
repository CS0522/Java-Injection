with open('E:\JavaInjection\handl_data\output_45.txt', 'r', encoding='utf-8') as f1, open('E:\JavaInjection\handl_data\outputdata6.txt', 'r', encoding='utf-8') as f2, open('output.txt', 'w', encoding='utf-8') as output:    
# 将第一个文件中的所有语句存储在列表中
    file1_lines = f1.readlines()        
    for line in f2:        
    # 如果第二个文件中的语句与第一个文件中的任何语句相同，则将其写入输出文件
        if line in file1_lines:            
            output.write(line)