n = int(input())
s = input()
if n == 1:
	print(0)
	exit()

for i in range(122, 96, -1):

	for k in range(len(s)):
		arr = []
		for j in range(len(s)):
			c = chr(i)
			if(j == 0 and ord(s[j+1])+1 == ord(s[j]) == i):
				arr += [j]
			elif(j == len(s)-1 and ord(s[j-1])+1 == ord(s[j]) == i):
				arr += [j]
			elif(j != 0 and j != len(s)-1 and (ord(s[j+1])+1 == ord(s[j]) == i or ord(s[j-1])+1 == ord(s[j]) == i)):
				arr += [j]
		new = ''
		for j in range(len(s)):
			if j in arr:
				continue
			new += s[j]

		s = new
		if len(s) == 1:
			break
		# print(s)
	if len(s) == 1:
		break
print(n-len(s))