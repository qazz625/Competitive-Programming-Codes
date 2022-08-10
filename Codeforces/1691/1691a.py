t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	even = 0
	odd = 0
	for x in arr:
		if x%2:
			even += 1
		else:
			odd += 1

	print(min(n-even, n-odd))


