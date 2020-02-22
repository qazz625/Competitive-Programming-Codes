t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	count = 0
	turn = 1
	# while a + turn <= b or b + turn <= a:
	# 	if a < b:
	# 		a += turn
	# 	else:
	# 		b += turn
	# 	# print(a, b, turn)

	# 	count += 1
	# 	turn += 1
	for i in range(0, 50000):
		x = (b-a)/2 + i*(i+1)/4
		y = (a-b)/2 + i*(i+1)/4
		# print(x, y, i)

		if x%1 == 0 and y%1 == 0 and a+x == b+y and x+y == i*(i+1)/2 and x >= 0 and y >= 0:
			ans = i
			break

	# if a != b:
	# 	count += 2*abs(a-b)

	# print(count)
	print(ans)