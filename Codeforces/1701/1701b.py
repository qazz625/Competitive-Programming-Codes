t = int(input())
for _ in range(t):
	n = int(input())
	arr = [0]*(n+1)

	cur = 1
	ans = [0]*n
	ind = 0
	while cur <= n:
		while cur <= n and arr[cur] == 1:
			cur += 1
		p = cur
		while cur <= n and p <= n:
			ans[ind] = p
			arr[p] = 1
			p *= 2
			ind += 1
	print(2)
	print(*ans)

