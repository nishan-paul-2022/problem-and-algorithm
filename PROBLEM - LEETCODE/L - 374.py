class Solution:
    def guessNumber(self, n):
        low, high = 1, n

        while low != high:
            mid = int((low + high) / 2)
            check = guess(mid)
            if check == -1:
                high = mid - 1
            if check == 1:
                low = mid + 1
            if check == 0:
                return mid
        return low


# if __name__ == '__main__':
# 	s = int(input())
# 	value = Solution().guessNumber(s)
# 	print(value)

# https://leetcode.com/problems/guess-number-higher-or-lower/solution/