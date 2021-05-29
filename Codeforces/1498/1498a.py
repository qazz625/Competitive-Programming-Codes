from collections import defaultdict

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	d = defaultdict(int)
	for x in arr:
		d[x] += 1

	arr = []
	for x in d:
		arr += [[x, d[x]]]

	arr.sort()
	print(arr)


