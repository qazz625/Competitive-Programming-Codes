t = int(input())
for i in range(t):
	n, m = map(int, input().split())
	arr = [int(j) for j in input().split()]
	if m < n or n == 2:
		print(-1)
		continue

	su = 2*sum(arr)

	mi = min(arr[0], arr[1])
	prevmi = max(arr[0], arr[1])

	if arr[0] < arr[1]:
		ind1 = 0
		ind2 = 1
	else:
		ind2 = 0
		ind1 =1

	for x in range(2, len(arr)):
		# print(mi, prevmi)
		if arr[x] < mi:
			prevmi = mi
			mi = arr[x]

			ind2 = ind1
			ind1 = x

		elif arr[x] < prevmi:
			ind2 = x
			prevmi = arr[x]

	m -= n
	su += m*(mi+prevmi)

	print(su)
	aa = []
	print(1, n)
	for j in range(1, n):
		print(j, j+1)

	for j in range(m):
		print(ind1+1, ind2+1)





