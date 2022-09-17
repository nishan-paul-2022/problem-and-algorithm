class Solution:
    def search(self, nums, target):
        a, b = 0, len(nums) - 1
        while a < b:
            mid = int((b + a) / 2)
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                a = mid + 1
            else:
                b = mid - 1
        if a == b and nums[a] == target:
            return a
        return -1


if __name__ == '__main__':
    nums = [12]
    target = 12
    ans = Solution().search(nums, target)
    print(ans)

# https://leetcode.com/problems/binary-search/