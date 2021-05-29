t = int(input())
for _ in range(t):
	n = int(input())
	n *= 2
	arr = [int(j) for j in input().split()]
	arr.sort()

	for i in range(n//2):
		print(arr[i], arr[-1-i], end=' ')

	print('')