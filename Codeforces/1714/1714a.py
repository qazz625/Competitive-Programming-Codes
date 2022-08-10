t = int(input())
for _ in range(t):
	n, h, m = map(int, input().split())
	ans = [40, 40]
	for i in range(n):
		hal, mal = map(int, input().split())
		if mal < m:
			ans = min(ans, [(hal-h-1)%24, (mal-m)%60])
		else:
			ans = min(ans, [(hal-h)%24, (mal-m)%60])
	print(*ans)