t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	ans = [[0 for i in range(m)] for j in range(n)]
	for i in range(0, m-1, 2):
		ans[0][i] = 1

	for i in range(0, n-1, 2):
		if ans[i][m-2] != 1:
			ans[i][m-1] = 1

	for i in range(m-1, 0, -2):
		if ans[n-2][i] != 1:
			ans[n-1][i] = 1

	for i in range(n-1, 0, -2):
		if ans[i][1] != 1:
			ans[i][0] = 1

	if ans[1][0] == 1:
		ans[1][0] = 0

	for x in ans:
		print(*x, sep='')
