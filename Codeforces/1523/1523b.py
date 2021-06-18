t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(j) for j in input().split()]

	ans = []

	for i in range(0, n, 2):
		a[i] = a[i] + a[i+1]
		ans += [[1, i, i+1]]

		a[i+1] = a[i+1] - a[i]
		ans += [[2, i, i+1]]

		a[i] = a[i] + a[i+1]
		ans += [[1, i, i+1]]

		a[i+1] = a[i+1] - a[i]
		ans += [[2, i, i+1]]

		a[i] = a[i] + a[i+1]
		ans += [[1, i, i+1]]

		a[i+1] = a[i+1] - a[i]
		ans += [[2, i, i+1]]

	# print(a)
	print(len(ans))
	for x in ans:
		print(x[0], x[1]+1, x[2]+1)