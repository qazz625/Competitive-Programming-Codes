t = int(input())
for _ in range(t):
	k = int(input())
	arr = [int(j)-1 for j in input().split()]

	k -= 1
	flag = 0
	ope = [0]*3
	while k != -1:
		if ope[k] == 1:
			break
		else:
			ope[k] = 1
			k = arr[k]

	if 0 in ope:
		print("NO")
	else:
		print("YES")
