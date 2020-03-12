t = int(input())
for _ in range(t):
	n = int(input())
	n = [int(j) for j in input().split()]
	for i in range(n):
		j=i
		while j != n and j-arr[j] == i - arr[i]:
			arr[j], arr[j] =