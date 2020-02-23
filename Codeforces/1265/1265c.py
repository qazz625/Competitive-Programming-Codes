from collections import defaultdict

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	d = defaultdict(int)

	for x in arr:
		d[x] += 1

	# print(d)

	num = []
	for x in d:
		num += [[x, d[x]]]

	num.sort(reverse=True)
	# print(num)

	pfx1 = []
	su = 0
	for i in range(len(num)):
		su += num[i][1]
		if su > n//2:
			break
		pfx1 += [num[i][:]]

	# print('lol',pfx1)

	if len(pfx1)<3:
		print(0, 0, 0)
		continue

	su1 = pfx1[0][1]
	su2 = 0
	su3 = 0

	fflag = 0
	for i in range(1, len(pfx1)):
		su2 += pfx1[i][1]
		if su2 > su1:
			ind = i+1
			fflag = 1
			break


	if fflag == 1:
		for i in range(ind, len(pfx1)):
			su3 += pfx1[i][1]

	if su3 <= su1 or su2 <= su1:
		print(0, 0, 0)
	else:
		print(su1, su2, su3)

