from random import randint
n = 3
arr = []
for i in range(n):
	sign = randint(0, 1)
	if sign == 1:
		arr += [['+', randint(1, 5)]]
	else:
		arr += [['-']]

print(n)
for x in arr:
	print(*x)
