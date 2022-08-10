t = int(input())
for _ in range(t):
	n, a, b = map(int, input().split())
	s = input()
	if b >= 0:
		print(a*len(s) + b*len(s))
	else:
		count = 0
		for i in range(1, len(s)):
			if s[i] == s[i-1]:
				continue
			else:
				count += 1

		count += 1
		num = count//2 + 1
		print(a*len(s) + num*b)
