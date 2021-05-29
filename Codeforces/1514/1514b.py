mod = 10**9 + 7

t = int(input())
for _ in range(t):
	n, k = map(int, input().split())

	# prod = 1
	# for i in range(k):
	# 	prod *= pow(2, n)-1
	# 	prod %= mod

	# print(prod)

	print(pow(n, k, mod))


'''
00
01
10
11

00
01


'''
