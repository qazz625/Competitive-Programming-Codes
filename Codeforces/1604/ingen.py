from random import randint

t = 1000
print(t)
MAX = 1000000000
for _ in range(t):
	x = 2*randint(1, MAX//2)
	y = 2*randint(1, MAX//2)
	print(x, y)