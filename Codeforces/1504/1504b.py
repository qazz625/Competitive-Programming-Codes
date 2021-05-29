t = int(input())
for _ in range(t):
	n = int(input())
	a = input()
	b = input()

	ans = "YES"
	arr = [0, 0]
	prefa = [0]*n
	prefb = [0]*n
	for i in range(n):
		if a[i] == '0':
			arr[0] += 1
		else:
			arr[1] += 1
		if arr[0] == arr[1]:
			prefa[i] = 1
		else:
			prefa[i] = -1

	arr = [0, 0]
	for i in range(n):
		if b[i] == '0':
			arr[0] += 1
		else:
			arr[1] += 1
		if arr[0] == arr[1]:
			prefb[i] = 1
		else:
			prefb[i] = -1

	for i in range(n):
		if prefa[i] != prefb[i]:
			ans = "NO"

	if ans == "NO":
		print("NO")
		continue

	ind = n-1
	while ind != -1 and prefa[ind] != 1:
		ind -= 1
	if ind == -1:
		if a == b:
			print("YES")
		else:
			print("NO")
		continue

	# print(prefa)
	# print(prefb)


	if a[ind+1:] != b[ind+1:]:
		print("NO")
		continue

	i = 0
	prev = 0
	flag = 0
	while i <= ind:
		cur = ''
		inv = ''
		while i <= ind and prefa[i] == -1:
			cur += a[i]
			inv += str(int(a[i])^1)
			i += 1

		cur += a[i]
		inv += str(int(a[i])^1)
		i += 1

		if b[prev:i] != cur and b[prev:i] != inv:
			flag = 1
			break
		prev = i

	if flag == 0:
		print("YES")
	else:
		print("NO")
