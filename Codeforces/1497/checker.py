f = open('outc.txt', 'r')
f2 = open('outp.txt', 'r')

num = 1
for i in range(100000):
	a = f.readline().strip()
	b = f2.readline().strip()

	if a != b:
		print("BREAK")
		print(num)
		break

	num += 1
