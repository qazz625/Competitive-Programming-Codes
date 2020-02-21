t = int(input())
for _ in range(t):
	n = int(input())
	arr = []
	for i in range(n):
		x,  y = map(int, input().split())
		arr += [[x, y]]
	arr.sort()
	x = 0
	y = 0
	flag = 0
	ans = ''

	for i in range(0, len(arr)):
		if arr[i][0] < x or arr[i][1] < y:
			flag = 1
			break
		else:
			ans += 'R'*(arr[i][0]-x)
			ans += 'U'*(arr[i][1]-y)
		x = arr[i][0]
		y = arr[i][1]
		
	if flag == 0:
		print("YES")
		print(ans)
	else:
		print("NO")

	# print(arr)