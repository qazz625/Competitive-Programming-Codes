from random import randint

nlim = 7
ailim = 3
t = 10
print(t)
for _ in range(t):
	n = randint(1, 7)
	arr = []
	for i in range(n):
		arr += [randint(-ailim, ailim)]
	print(n)
	print(*arr)