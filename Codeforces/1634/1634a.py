t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	s = input()
	if k == 0:
		print(1)
	elif s == s[::-1]:
		print(1)
	else:
		print(2)