t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	ans = []
	for i in range(k+1, n+1):
		ans += [i]

	if k%2 == 0:
		for i in range(k//2, k):
			ans += [i]
	else:
		for i in range(k//2+1, k):
			ans += [i]


	print(len(ans))
	print(*ans)
