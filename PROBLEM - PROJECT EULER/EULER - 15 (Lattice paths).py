

if __name__ == '__main__':
    sum = 0
    number = pow(2, 1000)
    number = str(number)
    for i in number:
        sum += int(i)
    print(sum)

