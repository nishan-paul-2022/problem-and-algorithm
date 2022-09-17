T = int(input())

for no in range(T):
    urlRaw = input()
    urlMod = urlRaw.replace('http:', 'https:')
    print(f'Case {no+1}: {urlMod}')
