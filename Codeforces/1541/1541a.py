t = int(input())
for _ in range(t):
	n = int(input())
	if n == 1:
		print(1)
		continue

	arr = []
	start = 1
	if n%2 == 1:
		arr = [3, 1, 2]
		start = 4

	for i in range(start, n+1, 2):
		arr += [i+1, i]

	print(*arr)
