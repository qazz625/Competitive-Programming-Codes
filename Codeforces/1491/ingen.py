from random import randint
t = 5
print(t)
for i in range(t):
	n = 5
	print(n)
	x = 500
	arr = []
	for j in range(n):
		arr += [randint(1, 5)]
	print(*arr)
