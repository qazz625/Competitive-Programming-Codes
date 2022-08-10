from random import randint

t = 100
print(t)
for _ in range(t):
	n = randint(1, 10)
	k = randint(1, 10)
	arr = []
	for i in range(n):
		arr += [randint(1, 4)]
	print(n, k)
	print(*arr)