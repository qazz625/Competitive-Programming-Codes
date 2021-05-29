from math import gcd

t = int(input())
for _ in range(t):
	p, a, b, c = map(int, input().split())

	arr = [a, b, c]
	ans = 10**20
	for x in arr:
		ans = min(ans, (x-(p%x))%x)

	print(ans)
