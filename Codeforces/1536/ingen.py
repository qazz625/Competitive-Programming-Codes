from random import randint

t = 10000
print(t)
for _ in range(t):
	n = randint(1, 10)
	print(n)
	s = ''
	for i in range(n):
		r = randint(1, 2)
		if r == 1:
			s += 'D'
		else:
			s += 'K'
	print(s)
