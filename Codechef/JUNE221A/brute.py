from random import randint
t = int(input())
for _ in range(t):
	x, n = map(int, input().split())
	ans = 0
	for i in range(30000):
		curx = x
		steps = 0
		while curx != 1:
			if randint(0, 1):
				curx += 1
				curx = min(curx, n)
			else:
				curx -= 1
			steps += 1
		ans += steps

	print(ans/30000)


'''
1 -> 0, 0, 0, 0, ...
2 -> 2, 4, 6, 8, 10, ...
3 -> 6, 10, 14, 18, ....
4 -> 12, 18, 24, ...
'''