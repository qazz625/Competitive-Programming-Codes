from random import randint

t = 1000
print(t)
for _ in range(t):
	n = 1000
	s = ''
	for i in range(n):
		r = randint(0, 2)
		if r == 2:
			s += '?'
		else:
			s += str(r)
	print(s)