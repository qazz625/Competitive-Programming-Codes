t = int(input())
MAXA = 1000
for _ in range(t):
	n = int(input())
	arr = []
	for i in range(n):
		x1, y1, x2, y2 = map(int, input().split())
		arr += [[x1, y1, x2, y2]]


	xdist = 10**10
	xcood = 10**10
	for x in range(-MAXA, MAXA+1):
		dist = 0
		for i in range(n):
			if arr[i][0] <= x <= arr[i][2]:
				dist += 0
			else:
				dist += min(abs(x-arr[i][0]), abs(x-arr[i][2]))
		if dist < xdist:
			xcood = x
			xdist = dist

	ydist = 10**10
	ycood = 10**10
	for y in range(-MAXA, MAXA+1):
		dist = 0
		for i in range(n):
			if arr[i][1] <= y <= arr[i][3]:
				dist += 0
			else:
				dist += min(abs(y-arr[i][1]), abs(y-arr[i][3]))
		if dist < ydist:
			ycood = y
			ydist = dist

	print("Case #{0}:".format(_+1), end=' ')
	print(xcood, ycood)


