t = int(input())
for i in range(t):
	s = input()
	lcount, rcount, ucount, dcount = 0, 0, 0, 0
	for x in s:
		if x == "U":
			ucount += 1
		elif x == 'D':
			dcount += 1
		elif x == "R":
			rcount += 1
		else:
			lcount += 1



	lr = min(lcount, rcount)
	ud = min(dcount, ucount)
	if ucount == 0 or dcount == 0:
		if lr == 0:
			print(0)
		else:
			print(2)
			print("LR")

	elif rcount == 0 or lcount == 0:
		if ud == 0:
			print(0)
		else:
			print(2)
			print("UD")

	else:
		print(2*(ud+lr))
		print("U"*ud + "L"*lr + "D"*ud + "R"*lr)