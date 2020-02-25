t = int(input())
for i in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	if len(arr) == 1:
		print(-1)
		continue

	ind = []
	for i in range(200010):
		ind += [[]]

	for i in range(n):
		ind[arr[i]] += [i]

	# print(*ind[:10])
	ans = 99999999
	prevans = 9999999999
	for x in ind:
		for y in range(len(x)-1):
			ans, prevans = min(ans, x[y+1]-x[y]), max(ans, x[y+1])

	print(ans+1)