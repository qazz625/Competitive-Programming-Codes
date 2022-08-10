from collections import defaultdict

t = int(input())
for _ in range(t):
	n = int(input())
	s = 'b'+input()
	n += 1

	flag = 10**10

	for i in range(n-1):
		if s[i] == s[i+1] == 'a':
			flag = min(flag, 2)

	for i in range(n-2):
		if s[i] == s[i+2] == 'a':
			flag = min(flag, 3)

	for i in range(n-3):
		if s[i] == s[i+3] == 'a' and (s[i+1:i+3] == 'bc' or s[i+1:i+3] == 'cb'):
			flag = min(flag, 4)


	if flag != 10**10:
		print(flag)
		continue

	pref = [(0, 0)]
	a, b, c = 0, 0, 0
	for i in range(1, n):
		if s[i] == 'a':
			a += 1
		elif s[i] == 'b':
			b += 1
		else:
			c += 1
		pref += [(a-b, a-c)]


	# print(pref)
	d = defaultdict(int)

	for i in range(n-2, -1, -1):
		find = (pref[i][0]+1, pref[i][1]+1)
		if find in d and d[find] - i != 1:
			flag = min(flag, d[find] - i)

		if pref[i+1] in d:
			d[pref[i+1]] = min(d[pref[i+1]], i)
		else:
			d[pref[i+1]] = i+1

	if flag == 10**10:
		print(-1)
	else:
		print(flag)

# a2 - a1 = b2 - b1 + 1 && a2 - a1 > c2 - c1
# a2-b2 - (a1-b1) = 1 && a2-c2 - (a1-c1) = 1

# x2 - x1 = 1 && y2 - y1 = 1