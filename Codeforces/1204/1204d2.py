s = input()
n = len(s)

arr = []
count = 1
for i in range(n-1):
	if s[i] != s[i+1]:
		arr += [count]
		count = 1
	else:
		count += 1

arr += [count]

if len(arr) == 1:
	print(n*'0')
	exit()
# print(arr)

if s[0] == '0':
	dp = [arr[0], arr[1]+arr[0]]
	for i in range(2, len(arr)):
		if i%2 == 1:
			dp += [arr[i] + max(dp[i-1], dp[i-2])]
		else:
			dp += [arr[i]+dp[i-2]]
	# print(dp)

else:
	dp = [arr[0], arr[1]]
	for i in range(2, len(arr)):
		if i%2 == 0:
			dp += [arr[i] + max(dp[i-1], dp[i-2])]
		else:
			dp += [arr[i]+dp[i-2]]
	# print(dp)

ans = [0]*n
print(dp)
z = max(dp)
o = n-z

# print(z, o)

for i in range(n-1):
	if s[i] == '1' and s[i+1] =='0':
		ans[i] = '1'
		ans[i+1] = '0'
		z -= 1
		o -= 1

# print(*ans)

for i in range(n):
	if ans[i] == 0 and z != 0:
		ans[i] = '0'
		z -= 1

for i in range(n):
	if ans[i] == 0:
		ans[i] = '1'
print(*ans, sep='')