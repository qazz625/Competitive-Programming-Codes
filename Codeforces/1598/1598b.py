t = int(input())
for _ in range(t):
	n = int(input())
	arr = []
	for i in range(n):
		arr += [[int(j) for j in input().split()]]

	ans = "NO"
	for i in range(5):
		for j in range(i+1, 5):
			one = 0
			two = 0
			three = 0
			for k in range(n):
				if arr[k][i] == 1 and arr[k][j] == 0:
					one += 1
				elif arr[k][i] == 0 and arr[k][j] == 1:
					two += 1
				elif arr[k][i] == 1 and arr[k][j] == 1:
					three += 1

			# print(i, j, one, two, three)

			if one < two:
				one, two = two, one

			# print(i, j, one, two, three)

			if three >= (one-two):
				three -= (one-two)
				two = one

				# print(i, j, one, two, three)


				if three%2 == 0 and one+three//2 == n//2:
					ans = "YES"

	print(ans)