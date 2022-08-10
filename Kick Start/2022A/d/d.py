t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	ans = 0
	for i in range(a, b+1):
		prod = 1
		tot = 0
		num = i
		while num != 0:
			prod *= num%10
			tot += num%10
			num //= 10

		if prod%tot == 0:
			ans += 1

	print("Case #{0}:".format(_+1), end=' ')
	print(ans)