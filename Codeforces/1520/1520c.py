t = int(input())
for _ in range(t):
	n = int(input())
	if n == 2:
		print(-1)
		continue

	num = 1

	arr = [[0 for i in range(n)] for j in range(n)]
	for i in range(n):
		for j in range(n):
			if (i+j)%2 == 0:
				arr[i][j] = num
				num += 1

	for i in range(n):
		for j in range(n):
			if (i+j)%2 == 1:
				arr[i][j] = num
				num += 1

	for x in arr:
		print(*x)