from collections import defaultdict


T = int(input())

for no in range(T):
    num = int(input())
    elements = list(map(int, input().split()))
    check = defaultdict(int)
    sum = 0

    for i in elements:
        check[abs(i)] = -1 if i < 0 else 1

    for i in check.keys():
        sum += i*check[i]

    print(f'Case {no+1}: {sum}')
