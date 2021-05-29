t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	ans = 0
	while sum(arr) != n:
		cur = 0
		while cur < n:
			if arr[cur] == 1:
				cur += 1
			else:
				arr[cur] -= 1
				cur += arr[cur]+1
		ans += 1
	print(ans)



