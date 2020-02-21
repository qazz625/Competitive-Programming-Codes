t = int(input())
for _ in range(t):
	n, d = map(int, input().split())
	arr = [int(j) for j in input().split()]

	tcount = 0
	for i in range(n):
		while arr[i] != 0 and d > 0:
			if d >= i:
				# print(arr[i], d)
				arr[i] -= 1
				d -= i
				tcount += 1
			else:
				break

	print(tcount)
