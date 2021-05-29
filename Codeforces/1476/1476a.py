t = int(input())
for _ in range(t):
	n, k = map(int, input().split())

	if n > k:
		s = 0
		e = 10**10
		while s <= e:
			mid = (s+e)//2
			if k*mid >= n:
				ans = mid
				e = mid-1
			else:
				s = mid+1
		k *= ans

	ans = k//n
	if k%n != 0:
		ans += 1
	print(ans)