class Solution:
    def sortedSquares(self, nums):
        for i in range(len(nums)):
            nums[i] = nums[i] * nums[i]
        nums.sort()
        return nums


if __name__ == '__main__':
    ans = Solution().sortedSquares([-4, -1, 0, 3, 10])
    print(ans)
# https://leetcode.com/problems/squares-of-a-sorted-array/
