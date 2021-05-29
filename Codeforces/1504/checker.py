def check(a):
	cur = 0
	for i in range(len(a)):
		if a[i] == '(':
			cur += 1
		else:
			cur -= 1
		if cur < 0:
			return 0
	if cur != 0:
		return 0
	return 1

for i in range(1000000):
	ans = input()
	if ans != "NO":
		lol = input()
		a = input()
		b = input()

		c = check(a)
		d = check(b)

		if c != 1 or d != 1 or len(a) != int(ans) or len(b) != int(ans):
			print(a)
			print(b)
			break