t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	if k == 1:
		print(k)
		continue


	mod = 10**9 + 7

	s = bin(k)[2:]
	l = len(s)

	ans = 0
	for i in range(len(s)-1, -1, -1):
		if s[i] == '1':
			ans += pow(n, (l-1)-i, mod)

	print(ans%mod)

