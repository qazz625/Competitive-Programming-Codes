t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	indices = []
	for i in range(1, n-1):
		if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
			indices += [i]

	# print(indices)

	ind = 0
	ans = 0
	while ind != len(indices):
		# print(ind)
		if ind != len(indices)-1 and indices[ind+1]-indices[ind] == 2:
			ans += 1
			arr[indices[ind]+1] = max(arr[indices[ind+1]], arr[indices[ind]])
			ind += 2
		else:
			ans += 1
			arr[indices[ind]] = max(arr[indices[ind]+1], arr[indices[ind]-1])
			ind += 1

	print(ans)
	print(*arr)
