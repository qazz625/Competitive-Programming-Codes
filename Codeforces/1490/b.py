t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	rem = [0, 0, 0]
	for x in arr:
		rem[x%3] += 1

	count = 0
	for i in range(102):
		if rem[i%3] > n//3:
			count += rem[i%3]-n//3
			rem[(i+1)%3] += rem[i%3]-n//3
			rem[i%3] = n//3

	print(count)
