t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	s = set()
	for i in range(n):
		arr[i] -= i
		s.add(arr[i])

	if len(s) >= 2:
		print(1)
	else:
		print(n)

