t = int(input())
for _ in range(t):
	c, d = map(int, input().split())
	if (c-d)%2 != 0:
		print(-1)
		continue

	if c == d:
		if c == 0:
			print(0)
		else:
			print(1)
	else:
		print(2)