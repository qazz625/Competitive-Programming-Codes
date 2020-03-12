t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	if m > n:
		print("NO")
	if m == n:
		print("YES")

	if m < n and n%m == 0:
		print("YES")
	else:
		print("NO")
