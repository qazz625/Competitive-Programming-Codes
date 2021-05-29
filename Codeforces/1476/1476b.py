t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	arr = [int(j) for j in input().split()]

	s = 0
	e = 10**18

	ans = -1
	while s <= e:
		mid = (s+e)//2

		denom = mid
		flag = 0
		for i in range(1, n):
			denom += arr[i-1]
			num = arr[i]

			if num*100 > denom*k:
				flag = 1

		if flag == 0:
			ans = mid
			e = mid-1
		else:
			s = mid+1
	print(ans)
