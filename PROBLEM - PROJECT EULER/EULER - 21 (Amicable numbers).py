from math import sqrt
from collections import defaultdict


def d(value):
    # print(f'\n{value}: ', end='')
    sum = 0
    limit = int(sqrt(value) + 1)
    offset = 2 if value % 2 else 1

    for i in range(1, limit, offset):
        j = int(value / i)
        if value % i == 0 and (i == j or i == 1):
            sum += i
            # print(f'{i} / ', end='')
        elif value % i == 0 and i != j:
            sum += i
            sum += j
            # print(f'{i} / {j} / ', end='')

    return sum


if __name__ == '__main__':
    sum = 0
    number = 10000
    map = dict()
    map = defaultdict(lambda: 1, map)

    for i in range(2, number + 1):
        value1 = d(i)
        value2 = d(value1)
        if i == value2 and i != value1 and map[i] == 1:
            print(f'{i} / {value1}')
            sum += i + value1
            map[value1] += 1

    print(sum)


# 220 / 284
# 1184 / 1210
# 2620 / 2924
# 5020 / 5564
# 6232 / 6368
# 31626
