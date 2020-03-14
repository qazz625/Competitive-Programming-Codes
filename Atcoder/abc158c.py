a, b = map(int, input().split())
flag = 0
for i in range(1, 10000):
	if int(i*0.08) == a and int(i*0.1) == b:
		print(i)
		flag = 1
		break

if flag == 0:
	print(-1)
