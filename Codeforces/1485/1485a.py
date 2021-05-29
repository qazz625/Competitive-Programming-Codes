t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	res = 9999
	for i in range(40):
		curb = b+i
		if curb == 1:
			continue
		ans = i
		cura = a
		while cura != 0:
			cura //= curb
			ans += 1
		res = min(res, ans)
	print(res)