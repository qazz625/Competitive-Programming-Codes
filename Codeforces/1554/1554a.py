t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	ans = -1
	for i in range(1, n):
		ans = max(ans, arr[i]*arr[i-1])
	print(ans)