class Solution:
	def reverseString(self, s):
		"""
		Do not return anything, modify s in-place instead.
		"""
		idx = len(s)
		j = idx
		idx = int(idx/2)

		for i in range(idx):
			j -= 1
			s[i], s[j] = s[j], s[i]

		return s


# if __name__ == '__main__':
# 	s = input()
# 	value = Solution().reverseString(s)
# 	print(value)

# https://leetcode.com/problems/reverse-string/