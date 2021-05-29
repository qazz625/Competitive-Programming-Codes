t = int(input())
for _ in range(t):
	n = int(input())
	arr = [20, 36, 51, 60, 76, 88, 99, 104]

	if n <= 4:
		print(arr[n-1])
		continue
	
	ind = n%4 + 4
	n -= n%4
	n -= 4
	print(n*11 + arr[ind-1]) 