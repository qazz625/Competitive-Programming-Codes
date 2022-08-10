t = int(input())
for _ in range(t):
	n = int(input())
	arr = [n]
	for i in range(1, n):
		arr += [i]
	print(*arr)