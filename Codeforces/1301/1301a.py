t = int(input())
for _ in range(t):
	a = input()
	b = input()
	c = input()

	ind = 0
	flag = 0
	for i in range(len(a)):
		if b[i] == c[i] or c[i] == a[i] or (a[i] == b[i] == c[i]):
			continue
		else:
			flag = 1
	if flag == 1:
		print("NO")
	else:
		print("YES")