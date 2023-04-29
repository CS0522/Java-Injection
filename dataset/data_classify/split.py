with open('E:\JavaInjection\handl_data\data5.txt', 'r', encoding='utf-8') as f1, open('outputdata5.txt', 'w', encoding='utf-8') as output:
    for line in f1:
        line = line.replace(" ", '')
        output.write(line)
