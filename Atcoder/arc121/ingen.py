from random import shuffle

t = 100
print(t)
for _ in range(t):
	n = 10
	arr = [i+1 for i in range(n)]


	shuffle(arr)
	print(n)
	print(*arr)