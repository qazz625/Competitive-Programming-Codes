t = int(input())
for _ in range(t):
	n, d, c, m = map(int, input().split())
	s = input()
	ind = 0
	while ind != n:
		if s[ind] == 'C' and c == 0:
			break
		elif s[ind]== 'C' and c != 0:
			c -= 1
		elif s[ind] == 'D' and d == 0:
			break
		else:
			d -= 1
			c += m
		ind += 1

	print("Case #{0}:".format(_+1), end=' ')
	if s[ind:].count('D') != 0:
		print("NO")
	else:
		print("YES")