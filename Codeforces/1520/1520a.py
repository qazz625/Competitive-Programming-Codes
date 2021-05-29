from collections import defaultdict
t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	flag = 0
	d = defaultdict(int)
	d[s[0]] += 1
	for i in range(1, len(s)):
		if s[i] != s[i-1]:
			d[s[i]] += 1
			if d[s[i]] > 1:
				flag = 1
	if flag == 1:
		print("NO")
	else:
		print("YES")
