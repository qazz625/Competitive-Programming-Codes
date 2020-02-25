def bringToCorrect(arr, s, ind, i):
	while arr[ind] < arr[ind-1]:
		# print(arr)
		# print(s)
		if ind+1 in s:
			s.remove(ind+1)
		else:
			break
		temp = arr[ind]
		arr[ind] = arr[ind-1]
		arr[ind-1] = temp
		ind -= 1



t = int(input())
for i in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	s = [i for i in range(2, n+1)]
	s = set(s)

	for i in range(1, n+1):
		if arr[i-1] == i:
			continue
		else:
			ind = 0
			while arr[ind] != i:
				ind += 1
			bringToCorrect(arr, s, ind, i)

	print(*arr)