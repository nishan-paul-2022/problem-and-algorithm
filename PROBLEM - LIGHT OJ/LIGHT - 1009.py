from collections import defaultdict


T = int(input())

for no in range(T):
    twod = list()
    frequency = defaultdict(int)
    frequency2 = defaultdict(int)
    frequency3 = defaultdict(int)
    ans = set()
    dd = defaultdict(list)
    n = int(input())

    for i in range(n):
        x, y = map(int, input().split())
        twod.append([x, y])
        frequency[x] += 1
        frequency[y] += 1
        frequency3[x] += frequency[y]
        frequency3[y] += frequency[x]

    for i in twod:
        x, y = i[0], i[1]
        if frequency2[x] != frequency2[y]:
            if frequency3[x] > frequency[y]:
                frequency2[x] += 1
                ans.add(x)
            else:
                frequency2[y] += 1
                ans.add(y)
        else:
            if frequency[x] < frequency[y]:
                frequency2[x] += 1
                ans.add(x)
            else:
                frequency2[y] += 1
                ans.add(y)

    print(f'Case {no+1}: {len(ans)}')