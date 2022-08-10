t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	arr = [int(j) for j in input().split()]
	ans = max(0, sum(arr) - m)
	print(ans)