t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	arr = [int(j) for j in input().split()]
	arr = list(set(arr))
	arr.sort()

	if k == 0:
		print(len(arr))
		continue

	if arr[0] != 0:
		mex = 0

	else:
		flag = 0
		for i in range(1, n):
			if arr[i] != arr[i-1]+1:
				flag = 1
				mex = arr[i-1]+1
		if flag == 0:
			mex = arr[-1] + 1


	ma = arr[-1]

	if mex == ma+1:
		print(len(arr)+k)
	else:
		new = (mex+ma)//2
		if (mex+ma)%2 != 0:
			new += 1

		if new in arr:
			print(len(arr))
		else:
			print(len(arr)+1)
