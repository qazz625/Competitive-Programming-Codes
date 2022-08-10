t = int(input())
for _ in range(t):
	a, b, c = map(int, input().split())
	print((a+2*b+3*c)%2)