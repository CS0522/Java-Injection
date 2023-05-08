input_file = ""
output_file = ""

with open(input_file, 'r', encoding='utf-8') as f1, open(output_file, 'w', encoding='utf-8') as output:
    for line in f1:
        line = line.replace(" ", '')
        output.write(line)
