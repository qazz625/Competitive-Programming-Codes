t = int(input())
for _ in range(t):
	s = input()
	n = len(s)

	cur = s[0]
	zero = 0
	one = 0
	for i in range(1, n):
		if s[i] != s[i-1]:
			if s[i-1] == '0':
				zero += 1
			else:
				one += 1
			cur = s[i]

	if s[-1] == '0':
		zero += 1
	else:
		one += 1

	if zero == 0 and one == 1:
		print(0)
	elif zero == 1:
		print(1)
	else:
		print(2)
