t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	one = m*(m+1)//2
	two = m*n*(n+1)//2
	print(one + two - m)