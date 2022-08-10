t = int(input())
for _ in range(t):
	n = int(input())
	top = [int(j) for j in input().split()]
	bot = [int(j) for j in input().split()]

	if n == 1:
		print(0)
		continue

	toppref = [top[0]]*n
	botpref = [bot[0]]*n
	for i in range(1, n):
		toppref[i] = toppref[i-1] + top[i]
		botpref[i] = botpref[i-1] + bot[i]

	topsuff = [top[n-1]]*n
	botsuff = [bot[n-1]]*n
	for i in range(n-2, -1, -1):
		topsuff[i] = topsuff[i+1] + top[i]
		botsuff[i] = botsuff[i+1] + bot[i]

	ans = 20**20
	for i in range(1, n-1):
		bob = max(botpref[i-1], topsuff[i+1])
		ans = min(ans, bob)

	ans = min(ans, topsuff[1])
	ans = min(ans, botpref[n-2])
	print(ans)



