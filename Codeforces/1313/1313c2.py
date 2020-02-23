n = int(input())
arr = [int(j) for j in input().split()]

inc = [arr[0]]
for i in range(1, n):
	inc += min(inc[i-1], arr[i])

dec = [arr[-1]]