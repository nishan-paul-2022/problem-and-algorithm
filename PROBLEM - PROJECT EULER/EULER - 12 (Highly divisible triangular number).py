from math import sqrt


def count_divisor(value, flag):
    print(f'{value} :::')
    n = 0
    limit = int(sqrt(value) + 1)
    offset = 2 if value % 2 else 1
    for i in range(1, limit, offset):
        if value % i == 0 and i == value/i:
            n += 1
            print(f'{i}', end=' / ')
        elif value % i == 0 and i != value/i:
            n += 2
            print(f'{i} / {int(value/i)}', end=' / ')
    print(f'\nnumber of divisor: {n}\n')
    return n > flag


if __name__ == '__main__':
    flag = 500
    xfactor = 1
    cnt = 1
    while not count_divisor(xfactor, flag):
        cnt += 1
        xfactor += cnt
    print(xfactor)
