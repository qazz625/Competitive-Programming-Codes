t = int(input())
for _ in range(t):
	n, k1, k2 = map(int, input().split())
	arr1 = [int(j) for j in input().split()]
	arr2 = [int(j) for j in input().split()]
	if max(arr1) > max(arr2):
		print("YES")
	else:
		print("NO")