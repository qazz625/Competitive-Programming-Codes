t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	su = sum(arr)

	if su%n != 0 or su//n not in arr:
		print("NO")
	else:
		print("YES")