t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	zero = s.count('0')
	if zero == 1:
		if n%2 == 0:
			print("ALICE")
		elif n%2 == 1 and s[n//2] == '1':
			print("ALICE")
		else:
			print("BOB")
		continue


	if s == s[::-1]:
		if zero%2 == 0:
			print("BOB")
		else:
			print("ALICE")

	else:
		if n%2 == 0:
			print("ALICE")
		elif n%2 == 1 and s[n//2] == '1':
			print("ALICE")
		else:
			if zero == 2:
				print("DRAW")
			else:
				print("ALICE")


