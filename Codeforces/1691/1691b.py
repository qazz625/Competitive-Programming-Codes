t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	arr += [10**10]
	ans = []
	cur = []

	flag = 0
	for i in range(n):
		if arr[i] != arr[i+1]:
			cur += [i]
			if len(cur) == 1:
				flag = 1
			for j in range(1, len(cur)):
				ans += [cur[j]+1]
			ans += [cur[0]+1]
			cur = []
		else:
			cur += [i]
		# print(cur, i)

	if flag == 1:
		print("-1")
	else:
		print(*ans)