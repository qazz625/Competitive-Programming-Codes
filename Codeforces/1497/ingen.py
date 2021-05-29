from random import randint
t = 100
print(t)
for i in range(t):
	n = 10
	k = 0
	arr = []
	for i in range(n):
		arr += [randint(1, 10**5)]

	print(n, k)
	print(*arr)
