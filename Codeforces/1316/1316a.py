t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	arr = [int(j) for j in input().split()]
	avg = sum(arr)

	x = sum(arr)%m
	y = sum(arr)//m

	ans = [0]*n
	for i in range(y):
		ans[i] = m

	if y != n:
		ans[y] = x

	for j in range(y+1, n):
		ans[j] = 0

	print(ans[0])
	# print

