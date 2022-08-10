t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	if arr[-1] == 0:
		ans = [i for i in range(1, n+2)]
		print(*ans)
		continue

	if arr[0] == 1:
		ans = [n+1] + [i for i in range(1, n+1)]
		print(*ans)
		continue

	ind = -1
	for i in range(n-1):
		if arr[i] == 0 and arr[i+1] == 1:
			ind = i
			break

	# print(arr)
	assert ind != -1

		# print(ind)
	ans = []
	for i in range(ind+1):
		ans += [i]

	ans += [n]
	for i in range(ind+1, n):
		ans += [i]

	for i in range(len(ans)):
		ans[i] += 1

	print(*ans)