from random import randint

t = 100
print(t)
for _ in range(t):
	n = 10
	upperlim = 10
	mlim = 200
	m = randint(1, mlim)
	print(n, m)
	for i in range(n):
		l = randint(1, upperlim)
		r = randint(l, upperlim)
		print(l, r)
