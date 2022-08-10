from collections import defaultdict

t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	arr = [int(j) for j in input().split()]
	sortarr = arr[:]
	sortarr.sort()


	d = defaultdict(int)
	for i in range(n):
		d[sortarr[i]] = i

	# print(d)

	count = 0
	for i in range(1, n):
		ind1 = d[arr[i-1]]
		ind2 = d[arr[i]]
		# print(ind1, ind2)

		if ind2 != ind1+1:
			count += 1
	# arr.sort()

	# print(count)



	if count+1 <= k:
		print("Yes")
	else:
		print("No")
	# print(count)