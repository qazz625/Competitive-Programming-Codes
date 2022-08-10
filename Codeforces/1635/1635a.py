t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	ans = [0]*40
	for x in arr:
		for i in range(35):
			if (1<<i)&x:
				ans[i] = 1

	tot = 0
	for i in range(40):
		tot += ans[i]*(1<<i)

	print(tot)