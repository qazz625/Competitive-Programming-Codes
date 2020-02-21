from math import ceil

t = int(input())
for _ in range(t):
	n, d  = map(int, input().split())
	prev = 0
	x = 0
	while True:
		test = ceil(d/(x+1))
		if test == prev:
			print("NO")
			break

		
		test2 = n-x
		if test<=test2:
			print("YES")
			break
		prev = test
		x += 1
