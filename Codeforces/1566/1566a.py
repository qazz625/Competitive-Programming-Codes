t = int(input())
for _ in range(t):
	n, s = map(int, input().split())

	nonzero = n//2 + 1

	print(s//nonzero)