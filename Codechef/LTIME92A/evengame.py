t = int(input())
for _ in range(t):
	n = int(input())
	s = sum([int(j) for j in input().split()])
	print(s%2 + 1)