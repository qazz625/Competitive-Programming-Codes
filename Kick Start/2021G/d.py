t = int(input())
for _ in range(t):
	n, a = map(int, input().split())
	print("Case #{0}:".format(_+1), end=' ')

	if n == 3:
		print("POSSIBLE")
		print(0, 0)
		print(0, 1)
		print(a, 0)

	if n == 4:
		if a <= 1:
			print("IMPOSSIBLE")
		else:
			print("POSSIBLE")
			print(0, 0)
			print(0, 1)
			print(a-1, 1)
			print(1, 0)

	if n == 5:
		if a <= 2:
			print("IMPOSSIBLE")
		else:
			print("POSSIBLE")
			print(0, 0)
			print(0, 1)
			print(2, a-1)
			print(1, 1)
			print(1, 0)
