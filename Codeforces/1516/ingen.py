from random import randint


t = 10000
print(t);
for _ in range(t):
	n = 10
	q = 100

	print(n, q)
	arr = [randint(1, 10) for j in range(n)]

	print(*arr)

	for i in range(q):
		l = randint(1, n)
		r = randint(l, n)

		print(l, r)



# print(1)
# print(10**5, 10**5)
# print(*([30030]*10**5))
# for _ in range(10**5):
# 	print(1, 10**5)