t = int(input())
for i in range(t):
	n, x, a, b = map(int, input().split())
	a, b = min(a, b), max(a, b)
	# print(a, b)
	while b < n and x != 0:
		# print("LL", b)
		b += 1
		x -= 1
	while a > 1 and x != 0:
		a -= 1
		x -= 1

	print(b-a)