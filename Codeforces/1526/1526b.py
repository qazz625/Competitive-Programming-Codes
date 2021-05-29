# s = set()
# for i in range(300):
# 	for j in range(300):
# 		if 11*i + 111*j <= 10**9:
# 			s.add(11*i + 111*j)

# s = list(s)
# s.sort()

# print(s)
# startind = 600
# print(s[startind])
# for i in range(startind, len(s)-1000):
# 	try:
# 		assert s[i] - s[i-1] == 1
# 	except:
# 		print(i, s[i], s[i-1])

s = set()
for i in range(200):
	for j in range(50):
		for k in range(10):
			if 11*i + 111*j + 1111*k <= 1200:
				s.add(11*i + 111*j + 1111*k)


t = int(input())
for _ in range(t):
	n = int(input())
	if n > 1200:
		print("YES")
	elif n in s:
		print("YES")
	else:
		print("NO")

