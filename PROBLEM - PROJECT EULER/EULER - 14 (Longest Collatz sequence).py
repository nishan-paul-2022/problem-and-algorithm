
if __name__ == '__main__':
    ans = -1
    count = -1
    for i in range(1, pow(10, 6)+1):
        n = i
        cnt = 1
        while n != 1:
            if n % 2 == 0:
                n = n / 2
            else:
                n = 3 * n + 1
            cnt += 1
        if cnt > count:
            ans = i
            count = cnt
    print(ans)
    print(count)

