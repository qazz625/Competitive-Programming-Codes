t = int(input())
for _ in range(t):
	n = int(input())
	if n%2050 != 0:
		print(-1)
		continue

	n //= 2050

	n = str(n)
	ans = 0
	for x in n:
		ans += int(x)
	print(ans)