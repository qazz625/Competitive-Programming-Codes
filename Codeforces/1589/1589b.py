t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	if n*m%3 == 0:
		print(n*m//3)
	else:
		rem1 = n%3
		rem2 = m%3
		ans = (n*m - rem1*rem2)//3
		if rem1*rem2 == 4:
			ans += 2
		elif rem1*rem2 == 1:
			ans += 1
		else:
			ans += 1
		print(ans)