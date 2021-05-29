t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	arr = [int(j) for j in input().split()]

	ind = 0
	while ind != n-1 and k != 0:
		if arr[ind] == 0:
			ind += 1
			continue

		arr[ind] -= 1
		arr[-1] += 1
		k -= 1

	print(*arr)