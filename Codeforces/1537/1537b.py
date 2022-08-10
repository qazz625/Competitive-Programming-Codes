t = int(input())
for _ in range(t):
	n, m, x, y = map(int, input().split())
	corners = [[1, 1], [n, 1], [1, m], [n, m]]

	ans = -1
	for i in range(4):
		for j in range(4):
			yo1 = corners[i][:]
			yo2 = corners[j][:]
			one = abs(x-yo1[0]) + abs(y-yo1[1])
			two = abs(yo1[0]-yo2[0]) + abs(yo1[1]-yo2[1])
			three = abs(yo2[0]-x) + abs(yo2[1]-y)
			if one+two+three > ans:
				ans = one+two+three
				pos1 = yo1[:]
				pos2 = yo2[:]


	print(*pos1, *pos2)

