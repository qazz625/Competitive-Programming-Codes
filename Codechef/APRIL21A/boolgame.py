from collections import defaultdict

inf = 10**20

t = int(input())
for _ in range(t):
	n, m, k = map(int, input().split())
	arr = [int(j) for j in input().split()]

	dp = [[-inf, -inf] for i in range(n)]

	d = defaultdict(int)

	for i in range(m):
		u, v, val = map(int, input().split())
		d[(u-1, v-1)] = val


	dp[0][0] = 0
	dp[0][1] = arr[0]

	#can be made to O(n^3)
	for i in range(1, n):
		dp[i][0] = max(dp[i-1][0], dp[i-1][1])
		for j in range(i, -1, -1):
			val = 0
			for x in range(j, i+1):
				val += arr[x]
				for y in range(x,i+1):
					val += d[(x, y)]
			if j != 0:
				dp[i][1] = max(dp[i][1], dp[j-1][0]+val)
			else:
				dp[i][1] = max(dp[i][1], val)

	print(max(dp[-1]))



