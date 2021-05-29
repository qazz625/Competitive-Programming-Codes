f1 = open("out1.txt", "r")
f2 = open("out2.txt", "r")
line = 1
for i in range(100000):
	a = f1.readline().strip()
	b = f2.readline().strip()
	if a != b:
		print(line)
	line += 1