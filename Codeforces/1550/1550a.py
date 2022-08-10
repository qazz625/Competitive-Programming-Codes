t = int(input())
for _ in range(t):
	n = int(input())
	cur = 0
	ans = 0
	for i in range(1, 1000000, 2):
		if cur+i > n:
			break
		ans += 1
		cur += i

	if cur == n:
		print(ans)
	else:
		print(ans+1)