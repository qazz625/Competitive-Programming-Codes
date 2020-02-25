from math import gcd

t = int(input())
for i in range(t):
	a, b = map(int, input().split())
	if gcd(a, b) != 1:
		print('infinite')
	else:
		print('finite')