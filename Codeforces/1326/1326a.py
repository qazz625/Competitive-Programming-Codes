t = int(input())
for _ in range(t):
	n = int(input())
	if n == 1:
		print(-1)
		continue

	if (n-1)%3 == 0:
		s = '2'*(n-2) + '3'*2
	else:
		s = '2'*(n-1) + '3'
	print(s)