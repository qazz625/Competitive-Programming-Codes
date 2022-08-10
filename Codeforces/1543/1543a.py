t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	if a == b:
		print(0, 0)
	else:
		if a < b:
			a, b = b, a

		ans = a-b
		print(ans, min(a%ans, (ans - a%ans)%ans))