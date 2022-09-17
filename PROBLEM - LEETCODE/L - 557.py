class Solution:
    def reverseWords(self, s):
        sr = s[::-1]
        sl = sr.split()
        sl.reverse()
        ans = ''
        n = len(sl)
        for i in range(n):
            if i < n-1:
                ans += sl[i] + ' '
            else:
                ans += sl[i]
        return ans


if __name__ == '__main__':
    s = input()
    ans = Solution().reverseWords(s)
    print(ans)

# https://leetcode.com/problems/reverse-words-in-a-string-iii/
