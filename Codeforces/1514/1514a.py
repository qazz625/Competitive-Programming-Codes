t = int(input())
s = set()
for i in range(200):
	s.add(i*i)

for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	flag = 0
	for x in arr:
		if x not in s:
			flag = 1
			break

	if flag == 0:
		print("NO")
	else:
		print("YES")