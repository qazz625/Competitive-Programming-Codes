t = int(input())
for _ in range(t):
	s = input()
	if s.count('a') == len(s):
		print("NO")
		continue

	a = 'a'+s
	b = s+'a'
	print("YES")
	if a != a[::-1]:
		print(a)
	elif b != b[::-1]:
		print(b)
