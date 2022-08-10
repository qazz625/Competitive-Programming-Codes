t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	ind = 0
	count = 0
	while ind < n-1:
		if arr[ind] > arr[ind+1]:
			count += 1
			ind += 2
		else:
			ind += 1
	print(count)