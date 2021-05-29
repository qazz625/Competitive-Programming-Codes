s = input()

present = []
for i in range(10):
	if s[i] == 'o':
		present += [str(i)]

ans = 0
for i in range(0, 10000):
	num = str(i)
	num = '0'*(4-len(num)) + num
	flag = 0
	for x in present:
		if x not in num:
			flag = 1

	for j in range(4):
		if s[int(num[j])] == 'x':
			flag = 1

	if flag == 0:
		ans += 1

print(ans)
