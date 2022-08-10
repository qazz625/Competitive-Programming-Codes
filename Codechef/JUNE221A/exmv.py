t = int(input())
for _ in range(t):
	x, n = map(int, input().split())	
	print((x-1)*(2*n-x))
