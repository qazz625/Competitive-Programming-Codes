def ask(s, i, j):
	print(s, i+1, j+1, flush=True)

n, k = map(int, input().split())

ask('and', 0, 1)
and01 = int(input())
ask('or', 0, 1)
or01 = int(input())

ask('and', 1, 2)
and12 = int(input())
ask('or', 1, 2)
or12 = int(input())

ask('and', 0, 2)
and02 = int(input())
ask('or', 0, 2)
or02 = int(input())

zero = ['?']*30
one = ['?']*30
two = ['?']*30

for i in range(30):
	if (1<<i)&and01:
		one[i] = 1
		zero[i] = 1
	elif ((1<<i)&or01) == 0:
		one[i] = 0
		zero[i] = 0

for i in range(30):
	if (1<<i)&and02:
		two[i] = 1
		zero[i] = 1
	elif ((1<<i)&or02) == 0:
		two[i] = 0
		zero[i] = 0

for i in range(30):
	if (1<<i)&and12:
		one[i] = 1
		two[i] = 1
	elif ((1<<i)&or12) == 0:
		one[i] = 0
		two[i] = 0

for i in range(30):
	if zero[i] == '?':
		zero[i] = one[i]^1
	if one[i] == '?':
		one[i] = zero[i]^1
	if two[i] == '?':
		two[i] = zero[i]^1
		
# print(zero)
# print(one)
# print(two)

first = 0
for i in range(30):
	first += (1<<i)*zero[i]

second = 0
for i in range(30):
	second += (1<<i)*one[i]

third = 0
for i in range(30):
	third += (1<<i)*two[i]

# print(first, second, third)

arr = [first, second, third]

for i in range(3, n):
	ask('and', 0, i)
	and0i = int(input())
	ask('or', 0, i)
	or0i = int(input())

	num = 0
	for j in range(30):
		if (1<<j)&and0i:
			num += (1<<j)*1
		elif ((1<<j)&or0i) == 0:
			num += (1<<j)*0
		elif (1<<j)&first:
			num += (1<<j)*0
		else:
			num += (1<<j)*1

	arr += [num]

arr.sort()
print('finish', arr[k-1], flush=True)

'''
7 6

1 6 4 2 3 5 4



'''