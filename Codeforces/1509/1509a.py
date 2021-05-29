t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	ans = []
	for x in arr:
		if x%2 == 0:
			ans += [x]
	for x in arr:
		if x%2 == 1:
			ans += [x]

	print(*ans)