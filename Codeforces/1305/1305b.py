# def findc

s = input()
n = len(s)

ma = -1
for i in range(n):
	c, o = [], []
	if s[i] == "(":
		for j in range(i+1):
			if s[j] == "(":
				c += [j]
		# print(c, o)
		for j in range(i+1, n):
			# print("LOL")
			if s[j] == ")":
				o += [j]
		# print(c, o)

		if min(len(o), len(c)) > ma:
			ma = min(len(o), len(c))
			if len(c) > len(o):
				ans = c[:len(o)] + o[:]
			else:
				ans = c + o[:len(c)]



	else:
		for j in range(i):
			if s[j] == "(":
				c += [j]
		for j in range(i, n):
			if s[j] == ")":
				o += [j]

		if min(len(o), len(c)) > ma:
			ma = min(len(o), len(c))
			if len(c) > len(o):
				ans = c[:len(o)] + o[:]
			else:
				ans = c + o[len(o)-1-len(c):len(o)-1]


	print(c, o)

if ma == 0 or ma == -1:
	print(0)
else:
	print(1)
	print(len(ans))
	for i in range(len(ans)):
		ans[i] += 1
	print(*ans)



# pfx = []

# c, o = 0, 0
# for i in range(n):
# 	if s[i] == '(':
# 		o += 1
# 	elif s[i] == ")":
# 		c += 1

# 	pfx += [[o, c]]

# print(*pfx)

# count = 0
# for i in range(len(pfx)):
# 	if s[i] == "(" and findc(i) == findo(i):


