t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	arr = [x for x in s]
	arr.sort()
	count = 0
	for i in range(n):
		if arr[i] != s[i]:
			count += 1
	print(count)