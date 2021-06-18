t = int(input())
mod = 10**9 + 7
for _ in range(t):
	n, m = map(int, input().split())
	a = pow(2, n, mod) - 1
	print(pow(a, m, mod))