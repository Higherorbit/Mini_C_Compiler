with open('output.txt', 'r') as file:
    contents = file.read()
    lines = contents.strip().split('\n')
    for line in lines:
        print(line.strip())
        