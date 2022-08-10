t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	c, d = map(int, input().split())
	arr = [a, b, c, d]
	z = arr.count(0)

	if z == 4:
		print(0)
	elif z == 0:
		print(2)
	else:
		print(1)
