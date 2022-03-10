from math import sqrt
from itertools import permutations


def sieve(n):
    mx = -1
    lmt = int(1 + sqrt(n))
    v = [0] * (n+1)
    prime = [2]

    for i in range(3, lmt + 1, 2):
        if v[i] == 0:
            for j in range(i * i, n + 1, 2 * i):
                v[j] = 1

    for i in range(3, n + 1, 2):
        if v[i] == 0:
            prime.append(i)
            mx = max(i, mx)

    print(prime)
    return mx


if __name__ == '__main__':
    mx = sieve(987654321)
    print(mx)


# https://projecteuler.net/problem=41