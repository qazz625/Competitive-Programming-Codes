t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	if min(n, m) <= 2:
		print(min(n, m))
	else:
		print(3)