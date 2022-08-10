t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	arr = [int(j) for j in input().split()]

	ans = 0
	for i in range(2**n):
		temp = []
		for j in range(n):
			if (1<<j)&i:
				temp += [arr[j]]

		count = 0
		for j in range(1, len(temp)):
			if temp[j] != temp[j-1]:
				count += 1
		if count <= k:
			ans = max(ans, len(temp))
	print(ans)
