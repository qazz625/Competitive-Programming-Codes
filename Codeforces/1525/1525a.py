from math import gcd

t = int(input())
for _ in range(1, t+1):
	n = int(input())
	print(100//gcd(100, n))

	# print(ans)