from collections import defaultdict

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	d = defaultdict(int)
	for i in range(n):
		arr[i] -= i

	for x in arr:
		d[x] += 1

	ans = 0
	for x in d:
		ans += d[x]*(d[x]-1)//2

	print(ans)

