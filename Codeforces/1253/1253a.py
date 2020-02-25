t =int(input())
for i in range(t):
	n = int(input())
	a = [int(j) for j in input().split()]
	b = [int(j) for j in input().split()]

	if a == b:
		print("YES")
		continue

	flag = 0

	for i in range(n):
		if a[i] > b[i]:
			flag = 1
			break

	if flag == 1:
		print("NO")
		continue

	ind = []
	diff = None
	for i in range(n):
		if a[i] != b[i]:
			diff = b[i] - a[i]
			break

	flag = 0
	for i in range(n):
		if a[i] != b[i] and b[i]-a[i] == diff:
			ind += [i]
		elif a[i] != b[i] and b[i]-a[i] != diff:
			# print(a[i], b[i])
			flag = 1
			break

	if flag == 1:
		print("NO")
		continue

	flag = 0
	# print(ind)

	for j in range(1, len(ind)):
		if ind[j] - ind[j-1] != 1:
			flag = 1
			break

	if flag == 0:
		print("YES")
	else:
		print("NO")

