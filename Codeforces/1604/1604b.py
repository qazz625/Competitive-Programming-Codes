t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	flag = 0
	for i in range(n-1):
		if arr[i] == arr[i+1]:
			flag = 1
			break

	if flag == 1:
		print("YES")
		continue

	s = arr[:]
	s.sort()

	if arr == s and n%2 == 1:
		print("NO")
	else:
		print("YES")