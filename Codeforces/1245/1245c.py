s = input()
if 'm' in s or 'w' in s:
	print(0)
	exit()

mod = 10**9 + 7

arr = []
count = 1
for i in range(len(s)-1):
	if s[i] == s[i+1] == 'n':
		count += 1
	elif s[i] == s[i+1] == 'u':
		count += 1

	else:
		if count != 1:
			arr += [count]
		count = 1

if count != 1:
	arr += [count]

ans = []
# print(arr)

res = 1
for x in arr:
	if x%2 == 0:
		res *= (pow(2, x//2-1, mod)*3-1)
	else:
		res *= (pow(2, x//2+1, mod)-1)
	res %= mod

print(res)








