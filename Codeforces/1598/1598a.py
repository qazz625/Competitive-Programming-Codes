t = int(input())
for _ in range(t):
	n = int(input())
	s1 = input()
	s2 = input()

	flag = 0
	for i in range(n):
		if s1[i] == '1' and s2[i] == '1':
			flag = 1

	# for i in range(n-1):
	# 	if s1[i] == '1' and s2[i+1] == '1':
	# 		flag = 1

	# for i in range(1, n):
	# 	if s1[i] == '1' and s2[i-1] == '1':
	# 		flag = 1

	if flag == 1:
		print("NO")
	else:
		print("YES")