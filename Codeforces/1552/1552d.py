t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	flag = 0
	sums = 0
	for i in range(1<<n):
		tot = 0
		for j in range(n):
			if i&(1<<j):
				tot += arr[j]

		for j in range(n):
			if (i&(1<<j)) == 0 and arr[j] == tot:
				flag = 1
		sums += tot
	if flag == 0:
		print("NO")
	else:
		print("YES")
