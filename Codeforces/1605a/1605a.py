t = int(input())
for _ in range(t):
	a, b, c = map(int, input().split())
	print(min((a+b-2*c) % 3, 1))

'''
a2 - a1 > b2 - b1 && a2 - a1 > c2 - c1
a2-b2 > a1-b1 && a2-c2 > a1-c1

x2 > x1 && y2 > y1

'''