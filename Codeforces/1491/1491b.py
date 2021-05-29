t = int(input())
for _ in range(t):
	n, u, v = map(int, input().split())
	arr = [int(j) for j in input().split()]
	if arr.count(arr[0]) == n:
		ans = min(2*v, u+v)
	else:
		ans = min(u, v)

	for i in range(1, n):
		if abs(arr[i] - arr[i-1]) >= 2:
			ans = 0

	print(ans)