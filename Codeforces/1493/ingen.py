from random import randint

n = 6
q = 50

print(n, q)

arr = []
for i in range(n):
	arr += [randint(1, 10)]

print(*arr)

for i in range(q):
	ind = randint(1, n)
	num = randint(1, 10)
	print(ind, num)
