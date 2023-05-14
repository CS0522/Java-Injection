input_file1 = "set1_所有被检出语句.txt"
input_file2 = "set1_所有被检出语句.txt"
output_file = "set1_重复语句.txt"

with open(input_file1, 'r', encoding='utf-8') as file1, open(input_file2, 'r', encoding='utf-8') as file2, open(output_file, 'w', encoding='utf-8') as output:    
# 将第一个文件中的所有语句存储在列表中
    file1_lines = file1.readlines()
    for line in file2:        
        count = 0
        for file1_line in file1_lines:
            if (line == file1_line):
                count += 1
        if (count > 1):
            output.write(line)