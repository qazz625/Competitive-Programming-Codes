t = int(input())
for _ in range(t):
	s = [int(j) for j in input().split()]

	s12 = max(s[0], s[1])
	s34 = max(s[2], s[3])

	s.sort(reverse=True)
	if max(s12, s34) == s[0] and min(s12, s34) == s[1]:
		print("YES")
	else:
		print("NO")