t = int(input())
for _ in range(t):
	n = int(input())
	ans = [n]
	for i in range(1, n):
		if i%2 == 1:
			ans += [ans[i-1]-(n-i)]
		else:
			ans += [ans[i-1]+(n-i)]
	ans.reverse()
	print(*ans)
