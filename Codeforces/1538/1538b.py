t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	su = sum(arr)

	if su%n != 0:
		print(-1)
		continue

	goal = su//n

	ans = 0
	for x in arr:
		if x > goal:
			ans += 1

	print(ans)

