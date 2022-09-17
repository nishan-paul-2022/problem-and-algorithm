from itertools import permutations


if __name__ == '__main__':
    sum = 0
    perms = [''.join(p) for p in permutations('0123456789')]

    for i in perms:
        if i[0] == '0':
            continue
        check = True
        if int(i[1:4]) % 2 != 0:
            check = False
        if int(i[2:5]) % 3 != 0:
            check = False
        if int(i[3:6]) % 5 != 0:
            check = False
        if int(i[4:7]) % 7 != 0:
            check = False
        if int(i[5:8]) % 11 != 0:
            check = False
        if int(i[6:9]) % 13 != 0:
            check = False
        if int(i[7:10]) % 17 != 0:
            check = False
        if check:
            sum += int(i)

    print(sum)


# d2d3d4=406 is divisible by 2
# d3d4d5=063 is divisible by 3
# d4d5d6=635 is divisible by 5
# d5d6d7=357 is divisible by 7
# d6d7d8=572 is divisible by 11
# d7d8d9=728 is divisible by 13
# d8d9d10=289 is divisible by 17