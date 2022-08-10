t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	ans = 0
	for x in s:
		ans += int(x)
		if x != '0':
			ans += 1

	# print('a', ans)

	if s[-1] != '0':
		ans -= 1

	print(ans)