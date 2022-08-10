import random
from random import randint

t = 1000
print(t)
for _ in range(t):
	primes = [2, 3, 5, 7, 11, 13]
	n = 10
	q = 10
	p = primes[random.randint(0, 5)]
	print(n, q, p)
	arr = []
	for i in range(n):
		arr += [random.randint(1, 1000)]
	print(*arr)

	for i in range(q):
		typ = random.randint(1, 2)
		if typ == 1:
			pos, val = random.randint(1, n), random.randint(1, 1000)
			print(typ, pos, val)
		else:
			s, l = randint(1, 4), randint(1, n)
			r = randint(l, n)
			print(typ, s, l, r)