f = open("in.txt", "w")
f.write("1000000 1000000 2")
n = 10**6
for i in range(1, n+1):
	f.write("{0} ".format(i))

f.write("\n")
for i in range(1, n+1):
	f.write("{0} ".format(i))