t = int(input())
for _ in range(t):
	a = [int(j) for j in input().split()]
	a.sort()

	if a[0] + a[1] == a[2] or (a[1] == a[2] and a[0]%2 == 0):
		print("YES")
	else:
		print("NO")
