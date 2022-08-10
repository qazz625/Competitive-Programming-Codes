k = int(input())
for _ in range(k):
	n, x, t = map(int, input().split())
	if t < x:
		print(0)
	else:
		if n > t//x:
			ans = t//x*(t//x+1)//2
			n -= t//x+1
			ans += t//x * n
		else:
			ans = n*(n-1)//2
		print(ans)
