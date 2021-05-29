from math import gcd

t = int(input())
for _ in range(t):
	oria, orib, c = map(int, input().split())
	a, b = max(oria, orib), min(oria, orib)
	# print(oria, orib, c)


	if a == 1:
		print(1, 1)
		continue

	numa = '2'+'0'*(a-1)

	if b == c:
		numb = '1'+'0'*(b-1)
		print(numa, numb)
		continue

	numb = ''
	for i in range(b-c+1):
		numb += '1'

	numb += '0'*(c-1)

	numc = '1'+'0'*(c-1)
	if oria > orib and int(numa) < int(numb):
		numa, numb = numb, numa
	if oria < orib and int(numa) > int(numb):
		numa, numb = numb, numa


	print(numa, numb)

	x = int(numa)
	y = int(numb)
	z = int(numc)

	g = gcd(x, y)



	assert len(numa) == oria
	assert len(numb) == orib
	assert len(numc) == c
	if gcd(x, y) != z:
		print(x, y, oria, orib, c)
	assert gcd(x, y) == z
