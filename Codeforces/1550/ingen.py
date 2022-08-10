from random import randint

t = 1
print(t)
for _ in range(t):
	n = 200000
	arr = []
	MAX = 10**9
	for x in range(n):
		arr += [randint(1, 10)]

	print(n)
	print(*arr)
