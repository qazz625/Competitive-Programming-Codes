t = int(input())
for _ in range(t):
	s = input()
	p = input()

	ind1, ind2 = 0, 0
	ans = 0
	while ind1 != len(s) and ind2 != len(p):
		if(s[ind1] == p[ind2]):
			ind1 += 1
			ind2 += 1
		else:
			ind2 += 1
	if ind1 == len(s):
		ans = 1


	print("Case #", end='')
	print(_+1, ":", end=' ', sep='')
	if ans == 0:
		print("IMPOSSIBLE")
	else:
		print(len(p)-len(s))