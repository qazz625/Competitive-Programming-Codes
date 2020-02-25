l, r = map(int, input().split())
for i in range(l, r+1):
	x = str(i)
	flag = 0
	# print(x)
	for y in x:
		if x.count(y) != 1:
			flag = 1
	if flag == 0:
		break
if flag == 0:
	print(x)
else:
	print(-1)