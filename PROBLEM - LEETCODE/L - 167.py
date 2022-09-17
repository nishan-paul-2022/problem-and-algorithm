class Solution:
    def twoSum(self, numbers, target):
        start = 0
        end = len(numbers) - 1
        while start <= end:
            sum = numbers[start] + numbers[end]
            if sum < target:
                start += 1
            elif sum > target:
                end -= 1
            else:
                return [start+1, end+1]


# if __name__ == '__main__':
#     ans = Solution().twoSum([2, 7, 11, 15], 9)
#     print(ans)

# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
