class Solution:
    def twoSum(self, nums, target):
        # nums.sort()
        n = len(nums)
        x, y = None, None
        for i in range(n):
            a = nums[i]
            b = target - a
            for j in range(i+1, n):
                if nums[j] == b:
                    x, y = i, j
                    break
        return [x, y]

# https://leetcode.com/problems/two-sum/
