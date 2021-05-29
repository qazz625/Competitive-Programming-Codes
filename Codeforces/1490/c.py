t = int(input())

s = set()
for i in range(1, 10001):
	s.add(i**3)

for _ in range(t):
	n = int(input())
	ans = "NO"
	for x in s:
		if n-x in s:
			ans = "YES"

	print(ans)