h, w = map(int, input().split())
r = [int(j) for j in input().split()]
c = [int(j) for j in input().split()]

arr = [[0 for j in range(w)] for j in range(h)]
temp = [[0 for j in range(w)] for j in range(h)]

flag = False

for i in range(h):
	for j in range(r[i]):
		temp[i][j] = 1
	try:
		temp[i][r[i]] = 2
	except IndexError:
		pass


for i in range(w):
	for j in range(c[i]):
		if temp[j][i] == 2:
			flag = True
		temp[j][i] = 1
	try:
		if temp[c[i]][i] == 1:
			flag = True
	except IndexError:
		pass

# for x in temp:
# 	print(*x)

if flag == True:
	print(0)
	exit()

# print(arr)


for i in range(h):
	for j in range(w):
		try:
			if r[i] >= j:
				arr[i][j] = 1
		except IndexError:
			pass


for i in range(w):
	for j in range(h):
		try:
			if c[i] >= j:
				arr[j][i] = 1
		except IndexError:
			pass


ans = 1
for x in arr:
	for y in x:
		if y == 0:
			ans *= 2
			ans %= 10**9 + 7
print(ans)