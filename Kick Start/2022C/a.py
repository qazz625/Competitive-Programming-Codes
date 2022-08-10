t = int(input())
for _ in range(t):
	n = int(input())
	s = input()

	specialchars = ['#', '@', '*', '&']

	upper = False
	lower = False
	digit = False
	special = False

	for x in s:
		if x.isupper():
			upper = True
		if x.islower():
			lower = True
		if x.isdigit():
			digit = True
		if x in specialchars:
			special = True

	if not upper:
		s += 'A'
	if not lower:
		s += 'a'
	if not digit:
		s += '1'
	if not special:
		s += '*'

	while len(s) < 7:
		s += '1'

	print("Case #{0}:".format(_+1), s)
