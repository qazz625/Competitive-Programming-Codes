def check(time):
	arr = time[:]
	arr[0] = str(arr[0])
	arr[1] = str(arr[1])
	if len(arr[0]) == 1:
		arr[0] = '0' + arr[0]
	if len(arr[1]) == 1:
		arr[1] = '0' + arr[1]

	for x in arr:
		for y in x:
			if dic[y] == '-1':
				return 0

	newarr = [dic[arr[1][1]] + dic[arr[1][0]], dic[arr[0][1]] + dic[arr[0][0]]]
	newarr[0] = int(newarr[0])
	newarr[1] = int(newarr[1])
	if newarr[0] < h and newarr[1] < m:
		return 1
	else:
		return 0

def fun(time):
	arr = time[:]
	arr[0] = str(arr[0])
	arr[1] = str(arr[1])
	if len(arr[0]) == 1:
		arr[0] = '0' + arr[0]
	if len(arr[1]) == 1:
		arr[1] = '0' + arr[1]
	print(*arr, sep=':')


t = int(input())
dic = {'0':'0', '1':'1', '2':'5', '3':'-1', '4':'-1', '5':'2', '6':'-1', '7':'-1', '8':'8', '9':'-1'}
for _ in range(t):
	h, m = map(int, input().split())

	time = input().split(':')
	time[0] = int(time[0])
	time[1] = int(time[1])

	c = check(time)
	if c == 1:
		fun(time)
		continue

	for i in range(h*m):
		time[1] += 1
		if time[1] == m:
			time[1] = 0
			time[0] += 1
			if time[0] == h:
				time[0] = 0
		c = check(time)
		if c == 1:
			fun(time)
			break
		