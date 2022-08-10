t = int(input())
for _ in range(t):
	a, b, c = map(int, input().split())
	tot = abs(b-a)*2

	if a > tot or b > tot or c > tot:
		print(-1)
	else:
		if c > tot//2:
			print(c - tot//2)
		else:
			print(c + tot//2)