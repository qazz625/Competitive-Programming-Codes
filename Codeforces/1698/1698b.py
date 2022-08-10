t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	arr = [int(j) for j in input().split()]
	if k == 1:
		print((n-1)//2)
		continue
	count = 0
	for i in range(1, n-1):
		if arr[i] > arr[i-1] + arr[i+1]:
			count += 1
	print(count)