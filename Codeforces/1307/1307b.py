from math import ceil

t = int(input())
for _ in range(t):
	n, x = map(int, input().split())
	arr = [int(j) for j in input().split()]

	if x in arr:
		print(1)
		continue

	ma = max(arr)

	if ma > x:
		print(2)
	else:
		print(ceil(x/ma))