t = int(input())
perfsq = []
for i in range(10000):
	perfsq += [i*i]
for _ in range(t):
	n, k = map(int, input().split())
	arr = [int(j) for j in input().split()]

	ind = 0
	cur = []
	ans = 0
	while ind != n:
		flag = 0
		for x in cur:
			if arr[ind]*x in perfsq:
				flag = 1
				break

		if flag == 1:
			ans += 1
			cur = []
		else:
			cur += [arr[ind]]
			ind += 1

	print(ans+1)
