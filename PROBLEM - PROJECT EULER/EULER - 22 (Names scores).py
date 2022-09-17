

if __name__ == '__main__':
    sum = 0
    names = list()
    with open("p022_names.txt", "r") as filestream:
        for line in filestream:
            currentline = line.split(",")
            names += currentline
    names = [i.replace('"', "") for i in names]
    names = sorted(names)
    for idx, i in enumerate(names):
        value = 0
        for j in i:
            value += ord(j)-ord('A')+1
        value *= (idx + 1)
        sum += value
    print(sum)