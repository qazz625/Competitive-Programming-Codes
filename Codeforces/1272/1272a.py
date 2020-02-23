t = int(input())
for _ in range(t):
	arr = [int(j) for j in input().split()]
	arr.sort()
	a, b, c = arr[0], arr[1], arr[2]

	if a == b == c:
		print(0)
	elif a == b and b != c:
		c -= 1
		if a == b == c:
			print(0)
		else:
			a += 1
			b += 1
			print(c-b+c-a)
	elif a != b and b == c:
		a += 1
		if a == b == c:
			print(0)
		else:
			b -= 1
			c -= 1
			print(c-a + b-a)

	else:
		a += 1
		c -= 1
		bb = (c-a + c-b + b-a)
		a -= 1
		c += 1

		a += 1
		b += 1
		cc = (c-a + c-b + b-a)
		a -= 1
		b -= 1

		b -= 1
		c -= 1
		aa = (c-a + c-b + b-a)

		print(min(aa, bb, cc))





		# print(x+y+z - 2)


