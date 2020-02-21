t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	s = sum(arr)
	count = 0
	for x in arr:
		if x%2 == 0:
			count += 1
	eve = count
	odd = n-count

	if s%2 == 0 and odd == n:
		print("NO")
	elif s%2 == 0 and eve == n:
		print("NO")
	else:
		print("YES")