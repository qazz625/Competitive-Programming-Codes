import random

t = 1
print(t)
for _ in range(t):
	n = 30000
	print(n, 1)
	for i in range(1, n):
		print(i, i+1)
	arr = [i for i in range(1, n+1)]
	arr2 = arr[::-1]

	arr2[0] = n+10

	print(*arr)
	print(*arr2)