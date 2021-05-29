import random


n = 3*10**5
q = 3*10**5

arr = [random.randint(1, n) for j in range(n)]

print(n, q)
print(*arr)
for i in range(q):
	l = random.randint(1, n)
	r = random.randint(l, n)
	print(l, r)
