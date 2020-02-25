from math import ceil

t = int(input())
for i in range(t):
	n = int(input())
	ar, ap, aS = map(int, input().split())
	s = input()

	br, bp, bs = 0, 0, 0
	for x in s:
		if x == 'R':
			br += 1
		elif x == 'P':
			bp += 1
		else:
			bs += 1

	su = min(ar, bs) + min(ap, br) + min(aS, bp)
	# print(su)
	if su >= ceil(n/2):
		print("YES")
		s = list(s)
		ans = [0]*n

		for i in range(n):
			if s[i] == 'R' and ap != 0:
				ans[i] = 'P'
				ap -= 1

			if s[i] == 'P' and aS != 0:
				ans[i] = 'S'
				aS -= 1

			if s[i] == 'S' and ar != 0:
				ans[i] = 'R'
				ar -= 1

		for i in range(n):
			if ans[i] == 0:
				if ap != 0:
					ans[i] = 'P'
					ap -= 1
				elif ar != 0:
					ans[i] = 'R'
					ar -= 1
				elif aS != 0:
					ans[i] = 'S'
					aS -= 1

		print(*ans, sep = '')

	else:
		print("NO")
