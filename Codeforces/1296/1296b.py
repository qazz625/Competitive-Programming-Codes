t = int(input())
for _ in range(t):
	n = int(input())
	ans = 0
	while n >= 10:
		ans += n - (n%10)
		cb = (n//10)
		n %= 10
		n += cb
		# print(n)
	ans += n
	print(ans)

