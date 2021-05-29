def ask(a, b, c):
	print(a, b, c, flush=True)

def ask2(a, b, c, d, e):
	print(a, b, c, d, e, flush=True)

def solvey(sx, ex, sy, ey):
	ask2(2, sx+1, sy, ex, ey)
	s = input()
	if s == "IN":
		ask2(2, sx+1, sy, ex, ey)
		s = input()
	elif s == "OUT":
		ask2(2, sx-1, sy, ex-2, ey)
		s = input()

def solvex(sx, ex, sy, ey):
	ask2(2, sx, sy, ex, ey-1)
	s = input()
	if s == "IN":
		ask2(2, sx, sy, ex, ey-1)
		s = input()
	elif s == "OUT":
		ask2(2, sx, sy+2, ex, ey+1)
		s = input()

def solve0(sx, ex, sy, ey):
	ex += 4-(ex-sx+1)
	ey += 4-(ey-sy+1)
	ask2(2, sx, sy, ex, ey)
	s = input()
	if s != "O":
		ask2(2, sx+1, sy+1, ex-1, ey-1)
		s = input()


lim = 11*10**17

t, q, d = map(int, input().split())
for _ in range(t):
	sx, ex, sy, ey = -lim, lim, -lim, lim
	ans = -1
	flag = 0
	while ex-sx >= 4 or ey-sy >= 4:
		midx = (sx+ex)//2
		midy = (sy+ey)//2
		ask(1, midx, midy)
		s = input()

		if s == 'O':
			flag = 1
			break

		if s[0] == 'X':
			sx = midx-1
			ex = midx+1
		elif s[0] == 'N':
			sx = midx
			ex += 1
		else:
			ex = midx
			sx -= 1

		if s[1] == 'Y':
			sy = midy-1
			ey = midy+1
		elif s[1] == 'N':
			sy = midy
			ey += 1
		else:
			ey = midy
			sy -= 1

	if flag == 1:
		continue

	if d == 0:
		solve0(sx, ex, sy, ey)
		continue

	if ey-sy == 2:
		ex += 4-(ex-sx+1)
		solvey(sx, ex, sy, ey)
	elif ex-sx == 2:
		solvex(sx, ex, sy, ey)
	else:
		ask2(2, sx, sy+1, ex, ey)
		s = input()

		if s == "O":
			continue

		if s == "IN":
			ask2(2, sx+1, sy+1, ex, ey)
			s = input()
			if s == "IN":
				ask2(2, sx+1, sy+1, ex, ey)
				s = input()
			elif s == "OUT":
				ask2(2, sx-1, sy+1, sx+1, sy+3)
				s = input()

		else:
			ask2(2, sx+1, sy-1, ex, ey-2)
			s = input()
			if s == "IN":
				ask2(2, sx+1, sy-1, ex, ey-2)
				s = input()
			elif s == "OUT":
				ask2(2, sx-1, sy-1, sx+1, sy+1)
				s = input()
