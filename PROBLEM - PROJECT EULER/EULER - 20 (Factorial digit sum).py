

if __name__ == '__main__':
    sum = 0
    factorial = 1
    number = 100
    for i in range(1, number+1):
        factorial *= i
    factorial = str(factorial)
    for i in factorial:
        sum += int(i)
    print(sum)
