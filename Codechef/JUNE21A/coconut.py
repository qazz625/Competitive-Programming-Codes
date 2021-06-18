t = int(input())
for _ in range(t):
	xa, xb, XA, XB = map(int, input().split())
	print(XA//xa + XB//xb)