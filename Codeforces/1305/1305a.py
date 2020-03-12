t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(j) for j in input().split()]
	b = [int(j) for j in input().split()]
	a.sort()
	b.sort()


	ans1 = [0]*n
	ans2 = [0]*n
	for i in range(n):
		ans1[i] = a[i]
		ans2[i] = b[i]
	print(*ans1)
	print(*ans2)