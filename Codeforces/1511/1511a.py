t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	print(arr.count(1) + arr.count(3))