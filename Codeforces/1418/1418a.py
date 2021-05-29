t = int(input())
for _ in range(t):
	x, y, k = map(int, input().split())
	coal_trades = (k*y-1)//(x-1)
	if (k*y-1)%(x-1) != 0:
		coal_trades += 1

	print(coal_trades)
