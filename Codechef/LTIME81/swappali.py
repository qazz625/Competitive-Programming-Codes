def solve(s, i, j):
	if j-i == 2:
		if s[j] == s[i] or s[i] == s[i+1]:
			return 1
		else:
			return 99999999
	if j-i == 1:
		if s[j] == s[i]:
			return 0
		else:
			return 99999999

	if s[i] == s[j]:
		return 1+solve(s, i+1, j-1)

	elif s[i] == s[j-1] and s[i+1] == s[j]:
		
		return 1+solve(s, i+2, j-2)



t = int(input())
for _ in range(t):
	n = int(input())
	arr = list(input())
	n = len(arr)
	print(solve(arr, 0, n-1))


	# dp = [[0, 0, 0]]
	# count = 0
	# ind = 1
	# while ind-1 < n//2:
	# 	print(i, n-i-1)
	# 	lol = [0, 0, 0]
	# 	if arr[i] == arr[n-i-1]:
	# 		lol[0] = min(dp[ind-1])
	# 		ind += 1

	# 	else:
	# 		lol[0] = 9999999999

	# 	if arr[i+1] == arr[n-i-1] and arr[i] == arr[n-i-2]:
	# 		lol[1] = 1+min(dp[ind-1])
			
	# 	else:
	# 		lol[1] = 9999999999

	# 	if arr[i] == arr[n-i-2] and arr[n-i-1] == arr[i+1]:
	# 		print("LOL")
	# 		lol[2] = 1+min(dp[ind-1])
			
	# 	else:
	# 		lol[2] = 9999999999

	# 	# if arr[i+1] == arr[n-i-2]:
	# 	# 	lol[3] = 2+min(dp[ind-1])
			
	# 	# else:
	# 	# 	lol[3] = 9999999999

		mi = min(lol)
		if mi == lol[1]:
			arr[i], arr[i+1] = arr[i+1], arr[i]
		elif mi == lol[2]:
			arr[n-i-1], arr[n-i-2] = arr[n-i-2], arr[n-i-1]
		elif mi == lol[3]:
			arr[n-i-1], arr[n-i-2] = arr[n-i-2], arr[n-i-1]
			arr[i], arr[i+1] = arr[i+1], arr[i]


	# 	dp += [lol]

	# # if n%2 == 0:
	# # 	if

	# print(*dp)



