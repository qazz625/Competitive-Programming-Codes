def check(n, goal):
	n = str(n)
	goal = str(goal)

	ans = 10**10
	ind = 0
	for i in range(len(n)):
		if ind != len(goal) and goal[ind] == n[i]:
			ind += 1

	return len(n) - ind + len(goal) - ind




s = set()
for i in range(63):
	s.add(2**i)

t = int(input())
for _ in range(t):
	n = int(input())
	# print(n)
	ans = 10**10
	for x in s:
		temp = check(n, x)
		ans = min(ans, temp)
	print(ans)