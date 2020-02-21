t = int(input())
for _ in range(t):
	n = int(input())
	n *= 2
	arr = [int(j) for j in input().split()]
	arr.sort()
	x = arr[n//2]
	y = arr[n//2 - 1]
	# print(x, y, n)
	# print(arr)
	print(x-y)

		# ans = []
		# temp1 = [arr[-1]]
		# temp2 = arr[:n]
		# print(temp1, temp2)
		# while len(temp2) != 1:
		# 	print("AA")
		# 	ans += [temp1[len(temp1)//2] - temp2[len(temp2)//2]]
		# 	x = temp2.pop()
		# 	y = temp2.pop()
		# 	temp1 += [x, y]
		# ans += [temp1[len(temp1)//2] - temp2[len(temp2)//2]]

		# print(ans)
