n = int(input())
arr = [int(j) for j in input().split()]

ma = 0

ans = []

for i in range(n):
	ans += [arr[i]+ma]
	ma = max(ma, ans[i])

print(*ans)
	# print(ma)