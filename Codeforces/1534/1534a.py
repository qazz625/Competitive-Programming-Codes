t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	arr = []
	for i in range(n):
		arr += [input()]

	sol1 = []
	sol2 = []

	for i in range(n):
		cur = ''
		for j in range(m):
			if (i+j)%2 == 0:
				cur += 'W'
			else:
				cur += 'R'
		sol1 += [cur]

	for i in range(n):
		cur = ''
		for j in range(m):
			if sol1[i][j] == 'R':
				cur += 'W'
			else:
				cur += 'R'
		sol2 += [cur]

	flag1 = 0
	flag2 = 0
	for i in range(n):
		for j in range(m):
			if arr[i][j] != '.' and arr[i][j] != sol1[i][j]:
				flag1 = 1
			if arr[i][j] != '.' and arr[i][j] != sol2[i][j]:
				flag2 = 1

	if flag1 == 0:
		print("YES")
		for x in sol1:
			print(x)
	elif flag2 == 0:
		print("YES")
		for x in sol2:
			print(x)
	else:
		print("NO")
