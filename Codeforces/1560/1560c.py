t = int(input())
for _ in range(t):
	k = int(input())
	k -= 1
	cur = 1
	add = 1

	row = 1
	col = 1
	while k-add >= 0:
		k -= add
		add += 2
		col += 1

	# print(k, col)

	for i in range(col-1):
		if k == 0:
			break
		row += 1
		k -= 1

	for i in range(col-1):
		if k == 0:
			break
		col -= 1
		k -= 1

	print(row, col)