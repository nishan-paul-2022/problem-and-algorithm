

if __name__ == '__main__':
    sum = 0
    number = 1000
    for i in range(1, number+1):
        sum += pow(i, i)
    sum = str(sum)
    ans = sum[len(sum)-10:len(sum)]
    print(ans)