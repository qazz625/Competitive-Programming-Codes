import copy

n, m = map(int, input().split())
dp = [[0 for i in range(n)] for j in range(m)]
# print(dp)
for i in range(n):
	dp[0][i] = n-i
mod = 10**9 + 7

# dp1 = [[0 for i in range(n)] for j in range(m)]

# for i in range(n):
# 	dp1[0][i] = 1

# for i in range(1, m):
# 	for j in range(n):
# 		dp1[i][j] = sum(dp1[i-1][:j+1])

# print(dp1)

dparr = []
for x in range(1, n+1):
	dp1 = [[0 for i in range(x)] for j in range(m)]

	for i in range(x):
		dp1[0][i] = 1

	for i in range(1, m):
		for j in range(x):
			dp1[i][j] = sum(dp1[i-1][:j+1])

	dparr += [copy.deepcopy(dp1)]
	# print(dp1)
# for i in range(1, m):
# 	for j in range(n):
# 		su = 0
# 		for k in range(n-j):
# 			su += dp[i-1][k]
# 			su %= mod
# 		dp[i][j] = su

# print(dp[:3])


# print(sum(dp[m-1])%mod)
su = 0
for i in range(1, n+1):
	for j in range(i, n+1):
		lol = sum(dparr[i-1][m-2])*sum(dparr[n-j][m-2])
		# print(i, j, lol)
		su += (sum(dparr[i-1][m-2])*sum(dparr[n-j][m-2]))%mod
		su %= mod

print(su)


