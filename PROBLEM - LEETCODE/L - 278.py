# isBadVersion(version)


class Solution:
    def firstBadVersion(self, n):
        a, b = 1, n
        minidx = 2147483648
        while a < b:
            mid = int((b + a) / 2)
            if isBadVersion(mid) == True:
                b = mid - 1
                minidx = min(minidx, mid)
            if isBadVersion(mid) == False:
                a = mid + 1

        if a == b and isBadVersion(a) == True:
            minidx = min(minidx, a)

        if minidx == 2147483648:
            return -1
        return minidx


if __name__ == '__main__':
    nums = [12]
    target = 12
    ans = Solution().search(nums, target)
    print(ans)

# https://leetcode.com/problems/first-bad-version/
