t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	if n <= 2:
		print(0)
	else:
		print(-max(arr))
