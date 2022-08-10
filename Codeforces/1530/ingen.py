from random import randint
t = 1000
print(t)
for i in range(t):
	n = randint(1, 8)
	arr = []
	brr = []
	for j in range(n):
		arr += [randint(1, 10)]
	for j in range(n):
		brr += [randint(1, 60)]
	print(n)
	print(*arr)
	print(*brr)