t = int(input())
for _ in range(t):
	s = input()
	if s.count(s[0]) == len(s):
		print("YES")
		continue

	n = len(s)


	arr1 = [0]*n
	arr0 = [0]*n

	ind = 0
	for i in range(1, n):
		arr0[i-1] = 1
		if s[i-1] == s[i] == '1':
			break

	for i in range(n-2, -1, -1):
		arr1[i+1] = 1
		if s[i+1] == s[i] == '0':
			break

	# print(s)
	# print(arr0)
	# print(arr1)

	flag = 0
	for i in range(1, n):
		if (arr0[i-1] & arr1[i]) == 1:
			print("YES")
			flag = 1
			break

	if flag == 0:
		print("NO")
