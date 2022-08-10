t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(j) for j in input().split()]
	b = [int(j) for j in input().split()]

	mp = [10**7]*(2*n + 1)
	for i in range(n):
		mp[b[i]] = i

	minmp = [0]*(2*n + 1)
	minmp[2*n] = mp[2*n]
	for i in range(2*n-1, -1, -1):
		minmp[i] = min(minmp[i+1], mp[i])


	# print(mp)
	# print(minmp)

	ans = 10**10
	for i in range(n):
		ans = min(ans, i+minmp[a[i]+1])

	print(ans)