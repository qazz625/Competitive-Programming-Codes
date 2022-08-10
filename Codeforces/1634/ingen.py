from random import randint

t = 1
print(t)
for i in range(t):
	n = 6
	print(n)
	arr = []
	for i in range(n):
		arr += [randint(1, 9)]

	arr[randint(0, n-1)] = 0
	print(*arr)
