from collections import defaultdict

t = int(input())
for _ in range(t):
	n, w = map(int, input().split())
	arr = [int(j) for j in input().split()]
	d = defaultdict(int)
	for x in arr:
		d[x] += 1

	arr = []
	for x in d:
		arr += [[x, d[x]]]

	arr.sort(reverse=True)
	# print(arr)

	cur = n
	ans = 0
	while cur != 0:
		rem = w
		for x in range(len(arr)):
			if arr[x][0] <= rem:
				red = rem//arr[x][0]
				if red <= arr[x][1]:
					arr[x][1] -= red
					rem -= red*arr[x][0]
					cur -= red
				else:
					rem -= arr[x][1]*arr[x][0]
					cur -= arr[x][1]
					arr[x][1] = 0
		# print(arr)
		ans += 1

	print(ans)




