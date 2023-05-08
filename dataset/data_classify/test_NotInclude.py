input_file1 = "dataset/data_classify/output_56.txt"
input_file2 = "dataset/data_classify/data_6.txt"
output_file = "dataset/data_classify/output_only6.txt"

with open(input_file1, 'r', encoding='utf-8') as file1, open(input_file2, 'r', encoding='utf-8') as file2, open(output_file, 'w', encoding='utf-8') as output:    
    # 文件中所有语句存储在列表中
    file1_lines = file1.readlines()
    file2_lines = file2.readlines()
    # file2 集合比 file1 集合更大
    # out_step 找 file2 中语句是第几行
    out_step = 0
    # in_step 找 file1 中语句是第几行
    in_step = 0

    for file2_line in file2_lines:
        out_step += 1
        in_step = 0
        # 标记是否匹配到 flag
        flag = False        
        for file1_line in file1_lines:
            in_step += 1
            if (file2_line == file1_line):
                flag = True
                break
        # 退出内循环后，如果 flag == False，说明没有匹配到
        if (flag == False):
            print("step(row) in file2(" + input_file2 + "): " + str(out_step))
            # print("step(row) in file1(" + input_file1 + "): " + str(in_step))
            print(file2_line)
            output.write(file2_line)
