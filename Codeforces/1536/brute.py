t = int(input())
for _ in range(t):
	n = int(input())
	s = input()

	ans = [0]*n
	for i in range(n):
		d, k = s[0:i+1].count('D'), s[0:i+1].count('K')
		for j in range(0, n, i+1):
			if j+i >= n:
				break

			dd, kk = s[j:j+i+1].count('D'), s[j:j+i+1].count('K')
			if d*kk == dd*k:
				ans[j+i] = max(ans[j+i], (j+i+1)//(i+1))
			else:
				break

	print(*ans, end=' \n')