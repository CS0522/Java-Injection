input_file1 = "dataset/data_classify/output_123.txt"
input_file2 = "dataset/data_classify/output_12.txt"
output_file = "dataset/data_classify/output_only12.txt"

with open(input_file1, 'r', encoding='utf-8') as file1, open(input_file2, 'r', encoding='utf-8') as file2, open(output_file, 'w', encoding='utf-8') as output:    
# 将第一个文件中的所有语句存储在列表中
    file1_lines = file1.readlines()
    for line in file2:        
    # 包含，则将其写入输出文件
        # if line in file1_lines:            
        #     output.write(line)
    # 不含，则将其写入输出文件
        if line not in file1_lines:            
            output.write(line)