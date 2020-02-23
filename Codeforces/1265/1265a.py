t = int(input())
for _ in range(t):
	s = input()
	flag = 0

	for i in range(len(s)-1):
		if s[i] == s[i+1] and s[i] in ['a', 'b', 'c']:
			flag = 1
			break

	if flag == 1:
		print(-1)
		continue

	arr = []

	s = list(s)

	flag = 0
	s = ['~'] + s + ['~']
	temp = []
	for i in range(len(s)-1):
		# print(i, s, len(s), s[i])
		if s[i+1] == '?' and flag == 0:
			temp += [s[i]]
			flag = 1
			continue

		if flag == 1:
			temp += [i]


		if flag == 1 and s[i+1] != '?':
			temp += [s[i+1]]
			arr += [temp[:]]
			temp = []
			flag = 0

	for x in arr:
		for y in ['a', 'b', 'c']:
			if y not in x:
				one = y

		for y in ['a', 'b', 'c']:
			if y != one and y != x[len(x)-1]:
				two = y

		lol = one

		for y in range(1, len(x)-1):
			s[x[y]] = lol
			if lol == one:
				lol = two
			else:
				lol = one

	for i in range(1, len(s)-1):
		print(s[i], end='')

	print('')
