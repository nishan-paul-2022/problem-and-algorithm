class Solution:
    def rotate(self, nums, k):
        n = len(nums)
        ans = [None] * n

        for i, j in zip(range(n-k, n), range(n)):
            ans[j] = nums[i]

        j = k
        for i in range(n-k):
            print(nums[i])
            ans[j] = nums[i]
            j += 1

        nums = ans
        return nums


if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5, 6, 7]
    Solution().rotate(nums, 3)
    print(nums)
