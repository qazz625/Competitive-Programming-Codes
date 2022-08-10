t = int(input())
for _ in range(t):
	s = input()
	ind = 0
	for i in range(len(s)-1, 0, -1):
		val = int(s[i]) + int(s[i-1])
		if val >= 10:
			ind = i-1
			break

	ans = ''
	itr = 0
	while itr != len(s):
		# print(itr, ind)
		if itr == ind:
			ans += str(int(s[ind]) + int(s[ind+1]))
			itr += 2
		else:
			ans += s[itr]
			itr += 1

	print(ans)


