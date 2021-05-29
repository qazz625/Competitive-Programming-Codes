import random
'''
rock -> 0 
paper -> 1
scissor -> 2
'''

def calcscore(oppo, us):
	if oppo == us:
		return e
	elif us - oppo == 1 or (us == 0 and oppo == 2):
		return w
	else:
		return 0

def sequential(method):
	global score, ans

	oppo = random.randint(0, 2)
	us = 0
	score += calcscore(oppo, us)
	arr[us] += 1
	ans += [us]

	oppo = 1
	us = 2
	score += calcscore(oppo, us)
	arr[us] += 1
	ans += [us]

	for i in range(2, 60):
		pr = round(arr[2]/i, 2)
		pp = round(arr[0]/i, 2)
		ps = round(arr[1]/i, 2)

		val = random.randint(0, 100)
		if val <= pr*100:
			oppo = 0
		elif val <= 100*pr + pp*100:
			oppo = 1
		else:
			oppo = 2

		if method == 'seq':
			if i%3 == 2:
				us = 1
			elif i%3 == 0:
				us = 0
			else:
				us = 2
		elif method == 'seq2':
			if i%2 == 0:
				us = 0
			else:
				us = 1
		elif method == 'adapt':
			if max(pr+pp, pp+ps, ps+pr) == pr+pp:
				us = 1
			elif max(pr+pp, pp+ps, ps+pr) == pr+ps:
				us = 0
			else:
				us = 2
		elif method == 'adapt2':
			if max(pr, pp, ps) == pr:
				us = 1
			elif max(pr, pp, ps) == pp:
				us = 2
			else:
				us = 0
		else:
			assert 0 == 1
			us = random.randint(0, 2)

		score += calcscore(oppo, us)
		arr[us] += 1
		ans += [us]


def only_2():
	global score, ans

	oppo = random.randint(0, 2)
	us = 0
	score += calcscore(oppo, us)
	arr[us] += 1
	ans += [us]

	break_point = 30

	for i in range(1, break_point):
		pr = round(arr[2]/i, 2)
		pp = round(arr[0]/i, 2)
		ps = round(arr[1]/i, 2)

		val = random.randint(0, 100)
		if val <= pr*100:
			oppo = 0
		elif val <= 100*pr + pp*100:
			oppo = 1
		else:
			oppo = 2

		us = 0
		# us = random.randint(0, 2)
		score += calcscore(oppo, us)
		arr[us] += 1
		ans += [us]

	for i in range(break_point, 60):
		pr = round(arr[2]/i, 2)
		pp = round(arr[0]/i, 2)
		ps = round(arr[1]/i, 2)

		val = random.randint(0, 100)
		if val <= pr*100:
			oppo = 0
		elif val <= 100*pr + pp*100:
			oppo = 1
		else:
			oppo = 2

		us = 2
		# print(pr, pp, ps, oppo, us)

		# us = random.randint(0, 2)
		score += calcscore(oppo, us)
		arr[us] += 1
		ans += [us]


t = int(input())
target = int(input())
totscore = 0
totzscore = 0
toteqscore = 0
tot10score = 0
for _ in range(t):
	print("Case #{0}:".format(_+1), end=' ')
	w, e = map(int, input().split())
	score = 0
	arr = [0, 0, 0]
	ans = []

	# if e == 0 or e == w//10:
	# 	sequential('seq')
	# else:
	# 	sequential('rand')
	if w == e:
		sequential('adapt')
	elif e == 0:
		sequential('adapt2')
	elif e == w//10:
		sequential('adapt')
	else:
		sequential('adapt')

	
	# print('score', score)
	for x in ans:
		if x == 0:
			print('R', end='')
		elif x == 1:
			print('P', end='')
		else:
			print('S', end='')
	print('')
	if e == 0:
		totzscore += score
	if e == w:
		toteqscore += score
	if e == w//10:
		tot10score += score
	totscore += score
# print(totscore/t)
# print(4*totzscore/t, 4*toteqscore/t, 4*tot10score/t)



