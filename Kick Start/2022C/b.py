t = int(input())
for _ in range(t):
	print("Case #{0}:".format(_+1), end=' ')

	n, x, y = map(int, input().split())

	tot = n*(n+1)//2

	if tot%(x+y) != 0:
		print("IMPOSSIBLE")
	else:
		print("POSSIBLE")
		req = (tot//(x+y)) * x
		ans = []
		# print(req)
		tot = 0
		for i in range(n, 0, -1):
			if tot < req and tot+i <= req:
				tot += i
				ans += [i]

		print(len(ans))
		print(*ans)