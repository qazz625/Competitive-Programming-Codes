t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(j) for j in input().split()]
	b = [int(j) for j in input().split()]

	if sum(a) != sum(b):
		print(-1)
		continue

	less = []
	more = []
	for i in range(n):
		if a[i] > b[i]:
			more += [[a[i]-b[i], i]]
		elif a[i] < b[i]:
			less += [[b[i]-a[i], i]]

	ans = []

	ptr1 = 0
	ptr2 = 0
	while ptr1 != len(more) and ptr2 != len(less):
		if more[ptr1][0] == 0:
			ptr1 += 1
			continue
		if less[ptr2][0] == 0:
			ptr2 += 1
			continue

		ans += [[more[ptr1][1]+1, less[ptr2][1]+1]]
		more[ptr1][0] -= 1
		less[ptr2][0] -= 1

	print(len(ans))
	for x in ans:
		print(*x)
