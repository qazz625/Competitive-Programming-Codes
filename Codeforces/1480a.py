t = int(input())
for _ in range(t):
	s = [x for x in input()]

	for i in range(len(s)):
		if i%2 == 0:
			if s[i] == 'a':
				s[i] = 'b'
			else:
				s[i] = 'a'
		else:
			if s[i] == 'z':
				s[i] = 'y'
			else:
				s[i] = 'z'

	print(*s, sep='')