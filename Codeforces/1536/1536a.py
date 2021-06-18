t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	arr.sort()
	if arr[0] < 0:
		print("NO")
		continue

	print("YES")
	ans = []
	for i in range(arr[-1]+1):
		ans += [i]

	print(len(ans))
	print(*ans)
