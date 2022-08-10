t = int(input())
for _ in range(t):
	s = input()
	arr = [x for x in s]
	arr.sort()
	print(*arr, sep='')