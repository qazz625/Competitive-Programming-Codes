t = int(input())
s = set()
for i in range(32):
	s.add(2**i)
for _ in range(t):
	n = int(input())
	if n == 1:
		print(3)
	elif n in s:
		print(n+1)
	else:
		for i in range(32):
			if (1<<i)&n:
				print(1<<i)
				break
