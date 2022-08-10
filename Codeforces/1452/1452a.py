t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	even, odd = 0, 0
	for x in arr:
		if x%2 == 0:
			even += 1
		else:
			odd += 1
	if even == odd:
		print("Yes")
	else:
		print("No")