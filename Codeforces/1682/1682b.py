t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	cur = -1
	for i in range(n):
		if arr[i] != i:
			if cur == -1:
				cur = arr[i]
			else:
				cur = cur&arr[i]

	print(cur)