t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	s = s+'~'

	count = 0
	arr = []
	for i in range(n):
		if s[i] == s[i+1]:
			count += 1
		else:
			count += 1
			arr += [[s[i], count]]
			count = 0

	print(arr[len(arr)//2][1])
	# print(arr)

