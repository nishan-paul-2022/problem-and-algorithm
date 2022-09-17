class Solution:
    def searchInsert(self, nums, target):
        a, b = 0, len(nums)-1
        ans = 0

        while a <= b:
            mid = int((a + b) / 2)
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                a = mid + 1
                ans = a
            if target < nums[mid]:
                b = mid - 1
                ans = mid

        return ans


if __name__ == '__main__':
    ans = Solution().searchInsert([1, 3, 5, 6], 2)
    print(ans)

# https://leetcode.com/problems/search-insert-position/
