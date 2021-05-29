t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	zero = s.count('0')
	if zero%2 == 0:
		print("BOB")
	else:
		if zero == 1:
			print("BOB")
		else:
			print("ALICE")
