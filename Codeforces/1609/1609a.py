t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	arr.sort()

	mult = 1
	for i in range(n):
		while arr[i]%2 == 0:
			mult *= 2
			arr[i] //= 2

	ans = sum(arr) - max(arr) + max(arr)*mult

	print(ans)