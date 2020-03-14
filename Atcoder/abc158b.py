n, a, b = map(int, input().split())
x = n//(a+b)
rem = n%(a+b)

if rem >= a:
	print(a + x*a)
else:
	print(rem + x*a)