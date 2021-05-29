t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	if n == 1:
		print(*arr)
		continue

	dp = [[0 for i in range(4)] for j in range(n)]

	dp[0][1], dp[0][2], dp[0][3] = 9999, 9999, 9999

	dp[0][0] = arr[0]

	if arr[1] == 1:
		dp[1][0] = 9999
		dp[1][1] = dp[0][0] + 1
		dp[1][2] = dp[0][0]
		dp[1][3] = 9999
	else:
		dp[1][0] = 9999
		dp[1][1] = dp[0][0]
		dp[1][2] = dp[0][0]
		dp[1][3] = 9999

	for i in range(2, n):
		if arr[i] == 0:
			dp[i][0] = min(dp[i-1][2], dp[i-1][3])
			dp[i][1] = dp[i-1][0]
			dp[i][2] = min(dp[i-1][0], dp[i-1][1])
			dp[i][3] = dp[i-1][2]
		else:
			dp[i][0] = min(dp[i-1][2], dp[i-1][3]) + 1
			dp[i][1] = dp[i-1][0] + 1
			dp[i][2] = min(dp[i-1][0], dp[i-1][1])
			dp[i][3] = dp[i-1][2]
	print(min(dp[-1]))




