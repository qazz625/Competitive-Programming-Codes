t = int(input())
for _ in range(t):
	n = int(input())
	s = input()

	assert n <= 20

	ans = "IMPOSSIBLE"
	for i in range(0, 1<<n):
		b = bin(i)[2:]
		b = '0'*(n-len(b)) + b
		# print(b)
		valid = 1
		for i in range(n):
			if s[i] != b[i] and s[i] != '?':
				valid = 0

		if valid == 0:
			continue

		if len(b) < 5:
			ans = "POSSIBLE"
			continue

		if b[:5] == b[4::-1]:
			valid = 0
		for i in range(1, n-4):
			# print(i+4, i-1)
			# print('aa', b[i:i+5], 'bb', b[i+4:i-1:-1])
			if b[i:i+5] == b[i+4:i-1:-1]:
				valid = 0

		if valid == 1 and len(s) == 5:
			ans = "POSSIBLE"
			continue

		if b[:6] == b[5::-1]:
			valid = 0
		for i in range(1, n-5):
			if b[i:i+6] == b[i+5:i-1:-1]:
				valid = 0

		if valid == 1:
			ans = "POSSIBLE"

	print("Case #{0}:".format(_+1), end=' ')
	print(ans)