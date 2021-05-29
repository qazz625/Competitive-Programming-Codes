from random import randint
from sys import stderr
import time

t = 2000
q = 100
d = 1
lim = 10**18

print(t, q, d, flush=True)

write = stderr.write
maxqcount = 0
for _ in range(t):
	curx, cury = randint(-lim, lim), randint(-lim, lim)
	# write(str(curx) + " " + str(cury) + "\n")
	# time.sleep(0.1)
	qcount = 0
	ans = -1
	while ans == -1 and qcount < q:
		arr = input()
		if arr == "NO GOOD":
			qcount += 1
			break

		arr = arr.split()
		if arr[0] == '1':
			x = int(arr[1])
			y = int(arr[2])
			if (curx, cury) == (x, y):
				s = "O"
				ans = 1
			else:
				s = ''
				if curx < x:
					s += 'P'
				elif curx == x:
					s += 'X'
				else:
					s += 'N'

				if cury < y:
					s += 'P'
				elif cury == y:
					s += 'Y'
				else:
					s += 'N'
		else:
			x1, y1, x2, y2 = int(arr[1]), int(arr[2]), int(arr[3]), int(arr[4])
			# write("CURRENT LOCATION: "+str(curx)+" "+str(cury)+"\n")
			if curx == x1 or curx == x2 or cury == y1 or cury == y2:
				s = "O"
				ans = 1
			elif x1 < curx < x2 and y1 < cury < y2:
				s = "IN"
			else:
				s = "OUT"
		# write(s+"\n")
		# write(str(curx) + " " + str(cury) + "\n")
		# time.sleep(0.5)
		print(s, flush=True)

		qcount += 1

		move = randint(1, 4)
		if move == 1:
			curx -= 1
		elif move == 2:
			curx += 1
		elif move == 3:
			cury -= 1
		elif move == 4:
			cury += 1


	# if qcount >= 67:
	# 	write(str(curx) + " " + str(cury) + "\n")

	maxqcount = max(maxqcount, qcount)

	write(str(qcount)+"\n")

write("MAX: " + str(maxqcount)+"\n")
