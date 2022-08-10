t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	num = abs(a-b)
	factors = 0

	i = 1
	while i*i <= num:
		if num%i == 0:
			factors += 2
			if i*i == num:
				factors -= 1
		i += 1

	print(factors)