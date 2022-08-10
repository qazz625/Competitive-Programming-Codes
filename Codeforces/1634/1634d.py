def ask(i, j, k):
	print('?', i+1, j+1, k+1, flush=True)

def answer(i, j):
	print('!', i+1, j+1, flush=True)


t = int(input())
for _ in range(t):
	n = int(input())

	cur = (-1, -1, -1)
	val = -1
	for i in range(2, n):
		ask(0, 1, i)
		x = int(input())
		if x > val:
			val = x
			cur = (0, 1, i)


	newind = cur[2]
	cur = (-1, -1, -1)
	val = -1
	for i in range(0, n):
		if i != 0 and i != newind:
			ask(0, newind, i)
			x = int(input())
			if x > val:
				val = x
				cur = (0, newind, i)

	for i in range(n):
		if i not in cur:
			remaining = i

	ask(cur[0], cur[1], remaining)
	a = int(input())

	ask(cur[1], cur[2], remaining)
	b = int(input())

	if a == val:
		answer(cur[0], cur[1])
	elif b == val:
		answer(cur[1], cur[2])
	else:
		answer(cur[2], cur[0])
