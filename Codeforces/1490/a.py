t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	count = 0
	for i in range(n-1):
		while arr[i] > 2*arr[i+1]:
			if arr[i]%2 == 1:
				arr[i] = arr[i]//2 + 1
			else:
				arr[i] //= 2
			count += 1

		while 2*arr[i] < arr[i+1]:
			arr[i] *= 2
			count += 1

	print(count)
