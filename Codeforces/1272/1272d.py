n = int(input())
arr = [int(j) for j in input().split()]
arr += [-10**18]
temp = []
count = [arr[0]]
for i in range(1, n+1):
	if arr[i] <= arr[i-1]:
		temp += [count]
		count = [arr[i]]
	else:
		count += [arr[i]]

ma = 0
for x in temp:
	if len(x) > ma:
		ma = len(x)

ans = []
for i in range(len(temp)-1):
	kk = 0
	if len(temp[i]) != 1 and len(temp[i+1]) != 1:
		if temp[i][-2] < temp[i+1][0]:
			kk = len(temp[i]) + len(temp[i+1]) - 1
		if temp[i][-1] < temp[i+1][1]:
			kk = len(temp[i]) + len(temp[i+1]) - 1

	elif len(temp[i]) != 1 and len(temp[i+1]) == 1:
		if i != len(temp)-2 and temp[i][-1] < temp[i+2][0]:
			kk = len(temp[i] + len(temp[i+2]))

	elif len(temp[i]) == 1 and len(temp[i+1]) != 1:
		if i >= 1 and temp[i-1][-1] < temp[i+1][0]:
			kk = len(temp[i-1]) + len(temp[i+1])

	else:
		if i >= 1 and temp[i-1][-1] < temp[i+1][0]:
			kk = len(temp[i-1]) + len(temp[i+1])
		if i != len(temp)-2 and temp[i][-1] < temp[i+2][0]:
			kk = max(len(temp[i] + len(temp[i+2])), kk)

	if kk != 0:
		ans += [kk]
if len(ans) == 0:
	ans = [-100]

print(max(max(ans), ma))

# count = 1
# i = 1
# while i != 