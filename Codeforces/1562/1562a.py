t = int(input())
for _ in range(t):
	l, r = map(int, input().split())
	print(r%max(l, r//2 + 1))