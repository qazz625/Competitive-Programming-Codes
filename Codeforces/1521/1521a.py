t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	if b == 1:
		print("NO")
	elif b == 2:
		print("YES")
		print(a, a*(2*b-1), 2*a*b)
	else:
		print("YES")
		print(a, a*(b-1), a*b)