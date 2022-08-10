from random import randint

t = 100
MAXA = 1000

print(t)
for _ in range(t):
	n = 20
	arr = []
	for i in range(n):
		x1 = randint(-MAXA, MAXA-1)
		x2 = randint(x1+1, MAXA)
		y1 = randint(-MAXA, MAXA-1)
		y2 = randint(y1+1, MAXA)
		arr += [[x1, y1, x2, y2]]
	print(n)
	for x in arr:
		print(*x)