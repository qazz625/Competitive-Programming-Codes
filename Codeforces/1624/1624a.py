t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	print(max(arr) - min(arr))