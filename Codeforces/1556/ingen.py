from random import randint

t = 1000
print(t)
for i in range(t):
	n = randint(1, 10)
	arr = []
	for j in range(n):
		arr += [randint(1, 10)]
	print(n)
	print(*arr)
