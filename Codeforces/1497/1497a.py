t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	freq = [0]*105

	for x in arr:
		freq[x] += 1

	# print(freq)

	ans = []
	for i in range(105):
		if freq[i] > 0:
			ans += [i]
			freq[i] -= 1

	for i in range(105):
		while freq[i] > 0:
			ans += [i]
			freq[i] -= 1

	print(*ans)