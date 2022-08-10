import random

n = 200000
k = 200000

perm = [i for i in range(1, n+1)]
random.shuffle(perm)
arr = [random.randint(1, 10) for i in range(n)]
print(n, k)
print(*arr)
print(*perm)
