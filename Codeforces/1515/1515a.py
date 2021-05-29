t = int(input())
for _ in range(t):
	n, x = map(int, input().split())
	arr = [int(j) for j in input().split()]
	if sum(arr) == x:
		print("NO")
		continue

	ind = 0
	tot = 0
	ans = []
	while ind != n:
		if tot + arr[ind] == x:
			break
		tot += arr[ind]
		ans += [arr[ind]]
		ind += 1

	if ind == n:
		print("YES")
		print(*ans)
		continue


	ans += [arr[ind+1]]
	ans += [arr[ind]]
	ind += 2
	while ind != n:
		# print(n, ind)
		ans += [arr[ind]]
		ind += 1

	print("YES")
	print(*ans)

