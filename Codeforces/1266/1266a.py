n = int(input())
for i in range(n):
	# print(i, n)
	s = input()
	if s.count('0') == 0:
		print("cyan")
		continue

	flag = 0
	for x in ['2', '4', '6', '8']:
		if x in s:
			flag = 1
			break

	if flag == 0 and s.count('0') >= 2:
		flag = 1

	if flag == 0:
		print('cyan')
		continue

	su = 0
	for x in s:
		su += int(x)

	if su%3 == 0:
		print("red")
	else:
		print("cyan")
