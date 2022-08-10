from collections import defaultdict

t = int(input())
for _ in range(t):
	arr = [[0 for i in range(3)] for j in range(3)]
	arr[0][0], arr[0][1], arr[0][2] = map(int, input().split())
	arr[1][0], arr[1][2] = map(int, input().split())
	arr[2][0], arr[2][1], arr[2][2] = map(int, input().split())

	d = defaultdict(int)
	ans = 0
	for i in range(3):
		if (arr[i][0] + arr[i][2])%2 == 0:
			if i == 1:
				d[(arr[i][0] + arr[i][2])//2] += 1
			elif i != 1 and arr[i][0] + arr[i][2] == 2*arr[i][1]:
				ans += 1

	# print(ans)

	for i in range(3):
		if (arr[0][i] + arr[2][i])%2 == 0:
			if i == 1:
				d[(arr[0][i] + arr[2][i])//2] += 1
			elif i != 1 and arr[0][i] + arr[2][i] == 2*arr[1][i]:
				ans += 1

	if (arr[0][0] + arr[2][2])%2 == 0:
		d[(arr[0][0] + arr[2][2])//2] += 1
	if (arr[0][2] + arr[2][0])%2 == 0:
		d[(arr[0][2] + arr[2][0])//2] += 1

	m = 0
	for x in d:
		m = max(m, d[x])

	print("Case #{0}:".format(_+1), ans+m)
