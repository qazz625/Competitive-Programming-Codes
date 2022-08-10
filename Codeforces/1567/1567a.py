t = int(input())
for _ in range(t):
	n = int(input())
	arr = []
	s = input()
	for x in s:
		if x == 'L' or x == 'R':
			arr += [x]
		elif x == 'D':
			arr += ['U']
		else:
			arr += ['D']

	print(*arr, sep='')
	

