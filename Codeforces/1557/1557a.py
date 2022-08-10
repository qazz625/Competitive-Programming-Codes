t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	ma = max(arr)

	ans = ma + (sum(arr)-ma)/(n-1)
	print(ans)
