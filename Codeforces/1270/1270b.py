t = int(input())
for i in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	flag = 0
	for i in range(1, n):
		if abs(arr[i]-arr[i-1]) > 1:
			flag = 1
			print("YES")
			print(i, i+1)
			break
	if flag == 0:
		print("NO")