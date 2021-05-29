import random

# t = 1000
# print(t)
# for i in range(t):
# 	n = 100
# 	m = random.randint(1, 200)
# 	x = random.randint(1, n)
# 	y = random.randint(1, n)
# 	print(n, m , x, y)
# 	s = set()
# 	while len(s) != m:
# 		a = random.randint(1, n)
# 		b = random.randint(a, n)
# 		c = random.randint(1, n)
# 		d = random.randint(c, n)
# 		if (a, b, c, d) not in s:
# 			s.add((a, b, c, d))

# 	for x in s:
# 		print(*x)

# 	print('')

t = 1
print(t)
for i in range(t):
	MAX = 20000
	n = MAX
	m = MAX-1
	x = MAX
	y = 1
	print(n, m, x, y)
	for i in range(MAX, 1, -1):
		print(i, i, i-1, i-1)