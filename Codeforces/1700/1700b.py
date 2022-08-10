t = int(input())
for _ in range(t):
	n = int(input())
	s = int(input())
	ans = 10**n + 1 - s
	if len(str(ans)) != n:
		print(ans + 10 + 10**(n-1))
	else:
		print(ans)