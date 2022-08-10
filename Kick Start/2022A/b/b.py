t = int(input())
for _ in range(t):

	s = input()
	n = len(s)
	tot = 0
	for i in range(len(s)):
		tot += int(s[i])

	add = (9-(tot%9))%9
	print("Case #{0}:".format(_+1), end=' ')


	if add == 0:
		print(s[0] + '0' + s[1:])
		continue

	maxarr = [0]*len(s)
	maxarr[0] = int(s[0])
	for i in range(1, n):
		maxarr[i] = max(int(s[i]), maxarr[i-1])

	# print(maxarr)

	ans = str(add) + s[0:]
	for i in range(n-1, -1, -1):
		if maxarr[i] <= add:
			ans = s[0:i+1] + str(add) + s[i+1:]
			break

	print(ans)