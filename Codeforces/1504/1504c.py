t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	if s[0] == '0' or s[-1] == '0' or s.count('0')%2 == 1 or s.count('1')%2 == 1:
		print("NO")
		continue

	zero = s.count('0')
	one = s.count('1')
	zopen = zero//2
	zclose = zero//2
	oopen = one//2
	oclose = one//2

	a = ''
	b = ''

	cura = 0
	curb = 0

	flag = 0
	for i in range(n):
		if s[i] == '1':
			if oopen > 0:
				a += '('
				b += '('
				cura += 1
				curb += 1
				oopen -= 1
			elif oclose > 0 and cura-1 >= 0 and curb-1 >= 0:
				a += ')'
				b += ')'
				cura -= 1
				curb -= 1
				oclose -= 1
			else:
				flag = 1

		else:
			if curb >= cura and zopen > 0:
				a += '('
				b += ')'
				cura += 1
				curb -= 1
				zopen -= 1
			else:
				a += ')'
				b += '('
				cura -= 1
				curb += 1
				zclose -= 1
			if cura < 0 or curb < 0:
				flag = 1
		# print(i, oopen, oclose, cura, curb, s[i])
		# print(a)
		# print(b)
	if flag == 1:
		print("NO")
	else:
		print("YES")
		print(a)
		print(b)


