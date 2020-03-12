t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	xor = 0
	ans = [0]*n
	ans[0] = xor
	for i in range(1, n):
		ans[i] = ans[i-1]^arr[i-1]
	print(*ans)
		