from random import randint

t = 1
print(t)

for _ in range(t):
	n = 200000
	p = 10**9
	arr = []
	for i in range(n):
		arr += [randint(1, 10**9)]

	print(n, p)
	print(*arr)