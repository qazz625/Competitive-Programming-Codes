t = int(input())
for _ in range(t):
	n = int(input())
	s = input()

	ind = -1
	for i in range(n//2, n):
		if s[i] == '0':
			ind = i
			break

	if ind != -1:
		# print("A")
		print(1, ind+1, 1, ind)

	elif s[n//2-1] == '0':
		# print("B")
		print(n//2+1, n, n//2, n)

	else:
		# print("C")
		print(n//2+1, n, n//2, n-1)