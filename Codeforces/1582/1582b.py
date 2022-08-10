t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	dp = [[0, 0] for i in range(n)]

	dp[0][0] = 1

	if arr[0] <= 1:
		dp[0][arr[0]] += 1

	for i in range(1, n):
		dp[i][0] += dp[i-1][0]
		dp[i][1] += dp[i-1][1]

		if arr[i] == 0:
			dp[i][0] += dp[i-1][0]
			dp[i][1] += dp[i-1][1]
		elif arr[i] == 1:
			dp[i][1] += dp[i-1][0]

	print(dp[-1][1])
