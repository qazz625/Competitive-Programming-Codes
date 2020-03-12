t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	arr = [-1] + arr + [-1]
	flag = 0
	for i in range(1, n+1):
		lol = arr.count(arr[i])
		if (lol == 2 and arr[i] != arr[i-1] and arr[i] != arr[i+1]) or lol >= 3:
			flag = 1
			break

	if flag == 1:
		print("YES")
	else:
		print("NO")