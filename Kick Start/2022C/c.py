t = int(input())
for _ in range(t):
	n, l = map(int, input().split())
	arr = []
	for i in range(n):
		x, d = map(int, input().split())
		arr += [[x, d, i]]

	arr.sort()

	# print(arr)

	right = [-1]*n
	left = [-1]*n

	dirright = -1
	for i in range(n):
		if arr[i][1] == 1:
			dirright = arr[i][0]
		right[i] = dirright

	dirleft = -1
	for i in range(n-1, -1, -1):
		if arr[i][1] == 0:
			dirleft = arr[i][0]
		left[i] = dirleft

	# print(right)
	# print(left)

	times = []

	for i in range(n):
		if arr[i][1] == 1:
			if i == n-1 or left[i+1] == -1:
				times += [[l-arr[i][0], arr[i][2]]]
			else:
				times += [[left[i+1], arr[i][2]]]

	for i in range(n-1, -1, -1):
		if arr[i][1] == 0:
			if i == 0 or right[i-1] == -1:
				times += [[arr[i][0], arr[i][2]]]
			else:
				times += [[l-right[i-1], arr[i][2]]]

	times.sort()
	print(times)

	print("Case #{0}:".format(_+1), end=' ')
	for x in times:
		print(x[1]+1, end=' ')
	print('')