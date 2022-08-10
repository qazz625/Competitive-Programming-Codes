from math import gcd

def solve(arr, ind, cur):
	global m, ans
	if ind == len(arr):
		g = cur[0]
		for i in range(1, len(cur)):
			g = gcd(g, cur[i])
		if sum(cur) <= m and g == 1:
			ans += 1
		return

	for i in range(arr[ind][0], arr[ind][1]+1):
		cur += [i]
		solve(arr, ind+1, cur)
		cur.pop()


t = int(input())
for _ in range(t):
	n, m = map(int, input().split())

	arr = []
	ans = 0
	for i in range(n):
		arr += [[int(j) for j in input().split()]]

	solve(arr, 0, [])

	print(ans)