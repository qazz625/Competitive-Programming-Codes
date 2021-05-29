t = int(input())
for _ in range(t):
	x, n = map(int, input().split())
	if n%x != 0:
		print(-1)
		continue

	n //= x
	time = 0
	mult = 1
	while n != 0:
		time += (n%2)*mult
		n //= 2
		mult += 1

	print(time)