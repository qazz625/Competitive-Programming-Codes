t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	oria, orib = a, b
	n = a+b

	case1 = ''
	case2 = ''

	for i in range(n):
		case1 += str(i%2)
		case2 += str((i+1)%2)

	print(case1)

	minc1 = 0
	maxc1 = 0
	for i in range(n):
		if case1[i] == '0' and a == 0:
			a -= 1
			minc1 += 1
		elif case1[i] == '1' and b == 0:
			b -= 1
			minc1 += 1
		elif case1[i] == '0' and a != 0:
			a -= 1
		elif case1[i] == '1' and b != 0:
			b -= 1
	# print(a, b)

	a, b = oria, orib
	for i in range(n):
		if case1[i] == '0' and b != 0:
			b -= 1
			maxc1 += 1
		elif case1[i] == '1' and a != 0:
			a -= 1
			maxc1 += 1
		elif case1[i] == '0' and b == 0:
			a -= 1
		elif case1[i] == '1' and a == 0:
			b -= 1

	print(minc1, maxc1)
	print(a, b, "AA")

	a, b = oria, orib
	minc2 = 0
	maxc2 = 0
	for i in range(n):
		if case2[i] == '0' and a == 0:
			a -= 1
			minc2 += 1
		elif case2[i] == '1' and b == 0:
			b -= 1
			minc2 += 1
		elif case2[i] == '0' and a != 0:
			a -= 1
		elif case2[i] == '1' and b != 0:
			b -= 1
	# print(a, b)

	a, b = oria, orib
	for i in range(n):
		if case2[i] == '0' and b != 0:
			b -= 1
			maxc2 += 1
		elif case1[i] == '1' and a != 0:
			a -= 1
			maxc2 += 1
		elif case2[i] == '0' and b == 0:
			a -= 1
		elif case2[i] == '1' and a == 0:
			b -= 1

	print(minc2, maxc2, "BB")


