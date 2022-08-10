from random import randint

t = 100
print(t)
for _ in range(t):
	n = randint(1, 12)
	print(n)
	arr = [1]
	for i in range(n-1):
		r = (arr[-1] + randint(-1, 1))%10
		arr += [r]
	print(*arr, sep='')