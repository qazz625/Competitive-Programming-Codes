def check(s, x, y):
	tot = 0
	for i in range(len(s)):
		if s[i] == '(':
			tot += 1
		else:
			tot -= 1
		if tot < 0:
			return 0

	if tot == 0:
		# print(x, y, s)
		return 1
	else:
		return 0

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	s = ''
	for i in range(n):
		if i%2 == 0:
			s += '('*arr[i]
		else:
			s += ')'*arr[i]

	# print(s)

	ans = 0
	for i in range(len(s)):
		for j in range(i+1, len(s)):
			ans += check(s[i:j+1], i, j)
	print(ans)