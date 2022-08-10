from collections import defaultdict

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	d = defaultdict(int)
	
	for x in arr:
		d[x] += 1

	num = sum(arr)
	denom = n

	s = []
	for x in d:
		s += [[x, d[x]]]

	s.sort()
	# print(s)

	ind1, ind2 = 0, len(s)-1

	ans = 0
	while ind1 <= ind2:
		# print(ind1, ind2)
		curnum = s[ind1][0] + s[ind2][0]
		curdenom = 2
		if num*curdenom < curnum*denom:
			ind2 -= 1
		elif num*curdenom > curnum*denom:
			ind1 += 1
		else:
			if ind1 != ind2:
				ans += s[ind1][1]*s[ind2][1]
			else:
				ans += s[ind1][1]*(s[ind1][1]-1)//2
			ind1 += 1
			ind2 -= 1

	print(ans)
