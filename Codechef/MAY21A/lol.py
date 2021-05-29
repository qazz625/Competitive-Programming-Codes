from math import gcd

k = 21
for k in range(1, 50):
	s = set()
	for i in range(1, 100):
		g = gcd(k+i*i, 2*i+1)
		s.add(g)
		# print(g)
	print(k, s, len(s))