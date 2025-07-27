class Solution:
    def reverseWords(self, original):
        s = original + ' '
        u = ['']
        n = 0

        for i in s:
            if i != ' ':
                u[n] += i
            else:
                n += 1
                u.append('')

        n -= 1
        while u[n] == '':
            n -= 1
        ans = u[n]

        while n > 0:
            n -= 1
            if u[n] != '':
                ans += ' ' + u[n]

        return ans


if __name__ == '__main__':
    s = input()
    value = Solution().reverseWords(s)
    print(value)

# https://leetcode.com/problems/reverse-words-in-a-string/
