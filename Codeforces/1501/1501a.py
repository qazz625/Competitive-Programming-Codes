t = int(input())
for _ in range(t):
	n = int(input())
	arr = [[0, 0]]
	for j in range(n):
		x, y = map(int, input().split())
		arr += [[x, y]]

	tm = [0]+[int(j) for j in input().split()]

	depart = 0
	for i in range(1, n+1):
		reqtime = arr[i][0] - arr[i-1][1] + tm[i]
		arrival = depart + reqtime

		temp = (arr[i][1] - arr[i][0])//2
		if (arr[i][1]-arr[i][0])%2 == 1:
			temp += 1

		depart = arrival+temp
		depart = max(depart, arr[i][1])

		# print(i, arrival, depart, reqtime)

	print(arrival)