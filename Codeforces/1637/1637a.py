t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	newarr = arr[:]
	newarr.sort()
	if arr == newarr:
		print("NO")
	else:
		print("YES")