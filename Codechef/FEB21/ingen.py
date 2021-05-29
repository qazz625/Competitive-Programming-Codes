import random

alphabets = 'abcdefghijklmnopqrstuvwxyz'

t = 1
print(t)
for _ in range(t):
	n = 20000
	s = set()
	for i in range(n):
		cur = ''
		for i in range(20):
			cur += alphabets[random.randint(0, 25)]
		assert cur not in s
		s.add(cur)

	print(n)
	for x in s:
		print(x)
