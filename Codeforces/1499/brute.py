from math import gcd

t = int(input())
for i in range(t):
	c, d, x = map(int, input().split())

	ans = 0
	for a in range(1, 1000):
		for b in range(1, 1000):
			g = gcd(a, b)
			l = a*b//g

			if c*l - d*g == x:
				ans += 1
				print(x, g)

	print(ans)