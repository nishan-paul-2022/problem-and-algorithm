class Solution(object):

	def scoreOfParentheses(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		n = len(s)
		stack = list()
		for i in range(n):
			if s[i] == '(':
				stack.append('(')
			else:
				if stack[-1] == '(':
					stack[-1] = 1
				else:
					inner_value = 0
					while stack[-1] != '(':
						inner_value += stack[-1]
						stack.pop()
					stack[-1] = 2*inner_value

		ans = 0
		for i in stack:
			ans += i
		return ans


if __name__ == '__main__':
	s = input()
	value = Solution().scoreOfParentheses(s)
	print(value)

# https://leetcode.com/problems/score-of-parentheses/
