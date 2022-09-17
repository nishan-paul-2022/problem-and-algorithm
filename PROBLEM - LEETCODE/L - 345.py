class Solution:
	def reverseVowels(self, s):
		vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
		s = list(s)
		idx = len(s)
		idy = 0
		vidx = list()

		for i in range(idx):
			if s[i] in vowels:
				vidx.append(i)
				idy += 1

		idz = idy
		idy = int(idy/2)
		for i in range(idy):
			idz -= 1
			s[vidx[i]], s[vidx[idz]] = s[vidx[idz]], s[vidx[i]]

		s = ''.join(s)
		return s

# if __name__ == '__main__':
# 	s = input()
# 	value = Solution().reverseVowels(s)
# 	print(value)

# https://leetcode.com/problems/reverse-vowels-of-a-string/