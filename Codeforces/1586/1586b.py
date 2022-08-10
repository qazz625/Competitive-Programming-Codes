t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	included = [0]*n

	for i in range(m):
		a, b, c = map(int, input().split())
		a -= 1
		b -= 1
		c -= 1
		included[b] = 1


	root = -1
	for i in range(n):
		if included[i] == 0:
			root = i

	assert root != -1

	for i in range(n):
		if i != root:
			print(i+1, root+1)