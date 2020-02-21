import copy

n = int(input())
arr = list(input())

temp = [[arr[0], '0', 0]]

flag = 0
for i in range(1, n):
	temp += [[arr[i], '9', i]]
	temp2 = copy.deepcopy(temp)
	temp2.sort()

	ind = i
	temps = []
	while temp[ind][0] != temp2[ind][0]:
		temps += [temp[ind-1][1]]
		temp[ind], temp[ind-1] = temp[ind-1][:], temp[ind][:]
		ind -= 1

	if len(temps) == 0:
		temp[ind][1] = temp2[-2][1]

	else:
		if temps.count(temps[0]) != len(temps):
			flag = 1
			break
		else:
			if temps[0] == '1':
				temp[ind][1] = '0'
			else:
				temp[ind][1] = '1'

if flag == 1:
	print("NO")
	exit()

print("YES")

ans = [0]*n

for x in temp:
	ans[x[2]] = x[1]

print(*ans, sep='')