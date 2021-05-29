t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	prefmax = [0]*n
	prefmax[0] = arr[0]
	for i in range(1, n):
		prefmax[i] = max(prefmax[i-1], arr[i])

	cur = n
	ind = n-1

	ans = []
	temp = []
	while ind != -1:
		if arr[ind] != cur:
			temp += [arr[ind]]
		else:
			temp += [arr[ind]]
			ans += temp[::-1]
			temp = []
			if ind != 0:
				cur = prefmax[ind-1]
		ind -= 1

	ans += temp[::-1]

	print(*ans)