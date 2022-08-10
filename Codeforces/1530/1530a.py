t = int(input())
for _ in range(t):
	n = input()
	ans = -1
	for x in n:
		ans = max(ans, int(x))
	print(ans)