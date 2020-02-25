t = int(input())
for i in range(t):
	a, b = map(int, input().split())
	x = abs(a-b)

	count = 0
	count += x//5
	x %= 5

	count += x//2
	x %= 2

	count += x//1

	print(count)