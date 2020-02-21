n = int(input())
arrr = [int(j) for j in input().split()]
arr = arrr[:]

for i in range(n):
	arr[i] = bin(arr[i])[2:]
	arr[i] = (30-len(arr[i]))*'0' + arr[i]

fflag = 0
ans = -1
for i in range(30):
	flag = 0
	ttemp = 0
	for j in range(n):
		if arr[j][i] == '1':
			flag += 1
		if flag == 1 and ttemp == 0:
			ttemp = 1
			ans  = j

		if flag == 2:
			break

	if flag == 1:
		fflag = 1
		break

if fflag == 0:
	print(*arrr)

else:
	kek = [arrr[ans]]
	for i in range(n):
		if i != ans:
			kek += [arrr[i]]
	print(*kek)


