alph = 'ab'

t = int(input())
for _ in range(t):
	s = input()
	ab = s.count('ab')
	ba = s.count('ba')

	if ab == ba:
		print(s)
	else:
		arr = []
		for x in s:
			if x == 'a':
				arr += [0]
			else:
				arr += [1]

		arr[0] ^= 1

		one = arr[:]
		arr[0]^= 1
		arr[-1] ^= 1

		two = arr[:]

		s1, s2 = '', ''

		for i in range(len(arr)):
			s1 += alph[one[i]]
			s2 += alph[two[i]]

		# print(s1, s2)

		if s1.count('ab') == s1.count('ba'):
			print(s1, sep='')
		else:
			print(s2, sep='')


# aaa
# aab
# aba
# abb
# baa
# bab
# bba
# bbb