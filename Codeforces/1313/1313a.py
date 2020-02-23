t = int(input())
for _ in range(t):
	arr = list(map(int, input().split()))
	arr.sort()
	count = 0
	a = arr[0]; b = arr[1]; c = arr[2]
	if arr[0] > 0 and arr[1] > 0 and arr[2] > 0:
		count += 3
		arr[0] -= 1
		arr[1] -= 1
		arr[2] -= 1
		# print(a, b, c)
		if arr[0] > 1 and arr[1] > 1 and arr[2] > 1:
			count += 3
			arr[0] -= 2
			arr[1] -= 2
			arr[2] -= 2
			if arr[0] > 0  and arr[1] > 0 and arr[2] > 0:
				count += 1
				print(count)
			else:
				print(count)

		else:
			for i in range(3):
				if arr[i] > 2:
					arr[i] = 2

			if arr == [0, 0, 1] or arr == [0, 0, 2] or arr == [0, 0, 0]:
				print(count)

			elif arr == [0, 1, 1] or arr == [0, 1, 2] or arr == [0, 2, 2] or arr == [1, 1, 1]:
				print(count+1)

			elif arr == [1, 1, 2] or arr == [1, 2, 2]:
				print(count+2)




	else:
		for i in range(3):
				if arr[i] > 2:
					arr[i] = 2

		if arr == [0, 0, 0]:
			print(0)

		elif arr == [0, 0, 1] or arr == [0, 0, 2]:
			print(1)

		elif arr == [0, 1, 1] or arr == [0, 1, 2]:
			print(2)
		elif arr == [0, 2, 2]:
			print(3)


	# if a > 0:
	# 	count += 1
	# 	a -= 1
	# if b > 0:
	# 	count += 1
	# 	b -= 1
	# if c > 0:
	# 	count += 1
	# 	c -= 1

	# if a > 0 and b > 0 and (c <= a or c <= b):
	# 	count += 1
	# 	a -= 1
	# 	b -= 1

	# if a > 0 and c > 0 and (b<= a or b<=c):
	# 	count += 1
	# 	a -= 1
	# 	c -= 1

	# if c > 0 and b > 0 and (a<=c or a <= b):
	# 	count += 1
	# 	c -= 1
	# 	b -= 1
	# if a > 0 and b > 0 and c > 0:
	# 	count += 1

	# print(count)