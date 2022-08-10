t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	a = [int(j) for j in input().split()]
	b = [int(j) for j in input().split()]
	arr = []
	for i in range(n):
		arr += [[a[i], b[i]]]

	arr.sort()

	for i in range(n):
		if k >= arr[i][0]:
			k += arr[i][1]

	print(k)