t = int(input())
for _ in range(t):
	n = int(input())
	if n <= 6:
		print(15)
		continue

	if n%2 == 1:
		n += 1
	print(n*5 // 2)
	