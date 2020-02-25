n, k = map(int, input().split())
s = input()
if k == 0:
	print(s)
	exit()

ans = ''
if n != 1:
	count = 0
	ind = 0
	if s[0] != '1':
		ans += '1'
		ind += 1
		count += 1
	else:
		ind += 1
		ans += '1'

	while count != k and ind != n:
		if s[ind] != '0':
			ans += '0'
			ind += 1
			count += 1

		else:
			ans += '0'
			ind += 1

	while ind != n:
		ans += s[ind]
		ind += 1

	print(ans)

else:
	print(0)
