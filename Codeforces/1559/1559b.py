t = int(input())
for _ in range(t):
	n = int(input())
	s = input()

	arr = [x for x in s]

	ind1 = 0
	ind2 = n-1
	while ind1 != n and s[ind1] == '?':
		ind1 += 1

	while ind2 != -1 and s[ind2] == '?':
		ind2 -= 1

	if ind1 == n:
		for i in range(n):
			if i%2 == 0:
				arr[i] = 'B'
			else:
				arr[i] = 'R'
		print(*arr, sep='')
		continue

	for i in range(ind1-1, -1, -1):
		if arr[i+1] == 'R':
			arr[i] = 'B'
		else:
			arr[i] = 'R'

	for i in range(ind2+1, n):
		if arr[i-1] == 'R':
			arr[i] = 'B'
		else:
			arr[i] = 'R'

	prev = arr[ind1]
	prevind = ind1
	count = 0
	ans = 0
	# print(ind1, ind2);
	for i in range(ind1+1, ind2+1):
		# print(i, arr[i])
		if arr[i] != '?':
			# print(i, count, prev, arr[i])
			if prev != arr[i] and count%2 == 0:
				ans += 0
			if prev == arr[i] and count%2 == 0:
				ans += 1
			if prev != arr[i] and count%2 != 0:
				ans += 1
			if prev == arr[i] and count%2 != 0:
				ans += 0

			for j in range(prevind+1, i):
				if arr[j-1] == 'R':
					arr[j] = 'B'
				else:
					arr[j] = 'R'
			prev = arr[i]
			prevind = i
			count = 0
		else:
			count += 1

	# print(ans)
	print(*arr, sep='')
