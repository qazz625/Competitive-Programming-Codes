t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	for i in range(n):
		arr[i] -= i+1

	ans = max(0, max(arr))
	print(ans)