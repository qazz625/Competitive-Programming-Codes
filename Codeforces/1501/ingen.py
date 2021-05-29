from random import randint

n = 10
print(n)
arr = []
for i in range(n):
	arr += [randint(1, 20)]

print(*arr)