t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	diff = [0]*(n+1)

	for i in range(n):
		if arr[i] == 0:
			continue

		r = i
		l = max(0, i-arr[i]+1)

		diff[l] += 1
		diff[r+1] -= 1

	for i in range(1, n):
		diff[i] += diff[i-1]

	for i in range(n):
		if diff[i] > 0:
			diff[i] = 1

	diff.pop()
	print(*diff)
