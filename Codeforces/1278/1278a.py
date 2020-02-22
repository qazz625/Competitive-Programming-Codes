from collections import defaultdict

t = int(input())
for i in range(t):
	p = input()
	pas = input()
	s1 = defaultdict(int)
	for x in p:
		s1[x] += 1

	# print(s1)
	flag = 0
	for j in range(len(pas)):
		s2 = defaultdict(int)
		for k in range(j, len(pas)):
			s2[pas[k]] += 1
			if s1 == s2:
				flag = 1
				break
		if flag == 1:
			break

	if flag == 1:
		print("YES")
	else:
		print("NO")
