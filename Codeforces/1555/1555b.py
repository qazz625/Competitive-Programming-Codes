t = int(input())
for _ in range(t):
	W, H = map(int, input().split())
	x1, y1, x2, y2 = map(int, input().split())
	w, h = map(int, input().split())
	flag = 0

	dx1 = x1
	dx2 = W-x2

	# print(dx1, dx2)

	req = max(0, w - max(dx2, dx1))
	if min(dx1, dx2) < req:
		xdist = 10**10
	else:
		xdist = req

	dy1 = y1
	dy2 = H-y2
	req = max(0, h - max(dy2, dy1))
	if min(dy1, dy2) < req:
		ydist = 10**10
	else:
		ydist = req

	# print(dy1, dy2, req)

	# if flag == 1:
	# 	print(-1)
	# else:
	ans = min(xdist, ydist)
	if ans == 10**10:
		print(-1)
	else:
		print(ans)

