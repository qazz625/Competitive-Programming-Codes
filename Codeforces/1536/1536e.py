mod = 10**9 + 7

t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	flag = 0
	count = 0
	for i in range(n):
		s = input()
		if '0' in s:
			flag = 1
		count += s.count('#')

	if flag == 0:
		print(pow(2, count, mod) - 1)
	else:
		print(pow(2, count, mod))
