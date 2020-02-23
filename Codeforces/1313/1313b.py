t = int(input())
for _ in range(t):
	n, a, b = map(int, input().split())
	sc = a+b
	if n >= sc-1:
		ma = sc-1
	else:
		ma = n

	if n >= sc:
		mi = 1
	else:
		mi = min((sc+1)-n, n)

	print(mi, ma)