from math import gcd

n, q = map(int, input().split())
arr = [int(j) for j in input().split()]
for i in range(q):
	ind, num = map(int, input().split())
	arr[ind-1] *= num

	g = 0
	for x in arr:
		g = gcd(g, x)
	print(g)