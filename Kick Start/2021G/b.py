t = int(input())
for _ in range(t):
	n = int(input())
	xarrfirst = [0]*n
	xarrsecond = [0]*n
	yarrfirst = [0]*n
	yarrsecond = [0]*n
	xset = set()
	yset = set()
	for i in range(n):
		x1, y1, x2, y2 = map(int, input().split())
		xarrfirst[i] = [x1, x2]
		xarrsecond[i] = [x2, x1]
		xset.add(x1)
		xset.add(x2)

		yarrfirst[i] = [y1, y2]
		yarrsecond[i] = [y2, y1]
		yset.add(y1)
		yset.add(y2)

	xarrfirst.sort()
	xarrsuff = [0]*n
	xarrsuff[n-1] = xarrfirst[n-1][0]
	for i in range(n-2, -1, -1):
		xarrsuff[i] = xarrsuff[i+1] + xarrfirst[i][0]

	xarrsecond.sort()
	xarrpref = [0]*n
	xarrpref[0] = xarrsecond[0][0]
	for i in range(1, n):
		xarrpref[i] = xarrpref[i-1] + xarrsecond[i][0]

	xset = list(xset)
	xset.sort()
	minx = 10**100
	xcood = 10**10
	for x in xset:
		s = 0
		e = n-1
		ans = -1
		#how many end before x
		while s <= e:
			mid = (s+e)//2
			if xarrsecond[mid][0] < x:
				ans = mid
				s = mid+1
			else:
				e = mid-1
		if ans == -1:
			xpref = 0
		else:
			xpref = (ans+1)*x - xarrpref[ans]

		s = 0
		e = n-1
		ans = -1
		while s <= e:
			mid = (s+e)//2
			if xarrfirst[mid][0] > x:
				ans = mid
				e = mid-1
			else:
				s = mid+1
		if ans == -1:
			xsuff = 0
		else:
			xsuff = xarrsuff[ans] - (n-ans)*x


		if xpref + xsuff < minx:
			xcood = x
			minx = xpref + xsuff

	yarrfirst.sort()
	yarrsuff = [0]*n
	yarrsuff[n-1] = yarrfirst[n-1][0]
	for i in range(n-2, -1, -1):
		yarrsuff[i] = yarrsuff[i+1] + yarrfirst[i][0]

	yarrsecond.sort()
	yarrpref = [0]*n
	yarrpref[0] = yarrsecond[0][0]
	for i in range(1, n):
		yarrpref[i] = yarrpref[i-1] + yarrsecond[i][0]

	yset = list(yset)
	yset.sort()
	miny = 10**100
	ycood = 10**10
	for y in yset:
		s = 0
		e = n-1
		ans = -1
		#how many end before x
		while s <= e:
			mid = (s+e)//2
			if yarrsecond[mid][0] < y:
				ans = mid
				s = mid+1
			else:
				e = mid-1
		if ans == -1:
			ypref = 0
		else:
			ypref = (ans+1)*y - yarrpref[ans]
		# print(ans)

		s = 0
		e = n-1
		ans = -1
		while s <= e:
			mid = (s+e)//2
			if yarrfirst[mid][0] > y:
				# print(mid)
				ans = mid
				e = mid-1
			else:
				s = mid+1
		if ans == -1:
			ysuff = 0
		else:
			ysuff = yarrsuff[ans] - (n-ans)*y

		# print('y', y, ypref, ysuff)



		if ypref + ysuff < miny:
			ycood = y
			miny = ypref + ysuff

	print("Case #{0}:".format(_+1), end=' ')
	print(xcood, ycood)


