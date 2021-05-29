t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	temp = []
	minpos = 10**10
	for x in arr:
		if x <= 0:
			temp += [x]
		else:
			minpos = min(minpos, x)

	if minpos == 10**10:
		print(len(temp))
	else:
		temp.sort()
		flag = 0
		for i in range(1, len(temp)):
			if temp[i] - temp[i-1] < minpos:
				flag = 1

		if flag == 0:
			print(len(temp)+1)
		else:
			print(len(temp))


