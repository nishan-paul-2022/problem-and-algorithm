class Solution:
    def mySqrt(self, x):
        start, end = 0, x
        mid = int((start+end)/2)

        while start <= end:
            v1 = mid*mid
            v2 = (mid+1)*(mid+1)

            if v1 <= x <= v2:
                if x == v2:
                    return mid+1
                return mid
            if v1 > x:
                end = mid-1
            if v2 < x:
                start = mid+1
            mid = int((start+end)/2)


# if __name__ == '__main__':
#     ans = Solution().mySqrt(16)
#     print(ans)


# https://leetcode.com/problems/sqrtx/