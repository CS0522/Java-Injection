input_file = "05_regular-anal/RE_demo_1.0/data/dataset_345.txt"
output_file = "dataset/data_payload_all.txt"

with open(input_file, 'r', encoding='utf-8') as f1, open(output_file, 'w', encoding='utf-8') as output:
    for line in f1:
        line = line.replace(" ", '')
        output.write(line)
