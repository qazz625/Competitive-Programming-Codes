n = int(input())
arr = [int(j) for j in input().split()]
ma = -1
for i in range(0, n):
	arr2 = arr[:]
	arr3 = arr[:]
	for j in range(i-1, -1, -1):
		if arr2[j] > arr2[j+1]:
			arr2[j] = arr2[j+1]

	for j in range(i+1, n):
		if arr2[j] > arr2[j-1]:
			arr2[j] = arr2[j-1]

	if sum(arr2) > ma:
		ma = sum(arr2)
		ans = arr2[:]

print(*ans)

