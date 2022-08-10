t = int(input())
for _ in range(t):
	empty = input()
	k, n, m = map(int, input().split())
	arr1 = [int(j) for j in input().split()]
	arr2 = [int(j) for j in input().split()]

	ptr1, ptr2 = 0, 0
	ans = []
	zerocount = k
	possible = 1
	while ptr1 != n and ptr2 != m:
		# print(arr1[ptr1], arr2[ptr2], zerocount)
		if arr1[ptr1] == 0:
			ans += [0]
			zerocount += 1
			ptr1 += 1
		elif arr2[ptr2] == 0:
			ans += [0]
			zerocount += 1
			ptr2 += 1
		elif arr1[ptr1] < arr2[ptr2] and zerocount >= arr1[ptr1]:
			ans += [arr1[ptr1]]
			ptr1 += 1
		elif arr2[ptr2] <= arr1[ptr1] and zerocount >= arr2[ptr2]:
			ans += [arr2[ptr2]]
			ptr2 += 1
		else:
			possible = 0
			break

	while ptr1 != n:
		if arr1[ptr1] == 0:
			ans += [0]
			zerocount += 1
			ptr1 += 1
		elif zerocount >= arr1[ptr1]:
			ans += [arr1[ptr1]]
			ptr1 += 1
		else:
			possible = 0
			break

	while ptr2 != m:
		if arr2[ptr2] == 0:
			ans += [0]
			zerocount += 1
			ptr2 += 1
		elif zerocount >= arr2[ptr2]:
			ans += [arr2[ptr2]]
			ptr2 += 1
		else:
			possible = 0
			break


	if possible == 0:
		print(-1)
	else:
		print(*ans)

