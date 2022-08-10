import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
	x, y = map(int, input().split())
	if x < y:
		x, y = y, x

	if x == 0 and y == 0:
		print(0)
		continue
	elif y == 0:
		print(-1)
		continue

	ans = 0
	while y*2 < x:
		y *= 2
		ans += 1

	if x == y:
		print(ans + x)
	else:
		print(ans + x + 1)
		