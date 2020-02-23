n, k = map(int, input().split())
s = input()
arr = set(input().split())

temp = []

aa = []
for x in s:
	if x in arr:
		aa += [x]
	else:
		if aa != []:
			temp += [len(aa)]
		aa = []

temp += [len(aa)]

su = 0
for x in temp:
	su += (x*(x+1))//2
print(su)