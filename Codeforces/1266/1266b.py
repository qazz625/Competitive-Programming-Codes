t = int(input())

tests = [int(j) for j in input().split()]
for n in tests:
	flag = 0
	base = [i for i in range(1, 15)]
	if n in base:
		print("NO")
		continue

	for i in range(1, 7):
		x = n-i
		if x%14 == 0:
			flag = 1
			break
	if flag == 1:
		print("YES")
	else:
		print("NO")
