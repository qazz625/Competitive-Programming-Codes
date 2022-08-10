t = int(input())
for _ in range(t):
	empty = input()
	xa, ya = map(int, input().split())
	xb, yb = map(int, input().split())
	xf, yf = map(int, input().split())
	cond1 = xa == xb == xf and min(ya, yb) < yf < max(ya, yb)
	cond2 = ya == yb == yf and min(xa, xb) < xf < max(xa, xb)

	if cond1 or cond2:
		print(abs(xa-xb) + abs(ya-yb) + 2)
	else:
		print(abs(xa-xb) + abs(ya-yb))