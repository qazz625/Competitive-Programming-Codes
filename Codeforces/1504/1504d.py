def place(a, b, c):
	print(a, b+1, c+1, flush=True)

n = int(input())

one = []
two = []

for i in range(n):
	for j in range(n):
		if (i+j)%2 == 0:
			one += [[i, j]]
		else:
			two += [[i, j]]

count = 0
ptr1 = 0
ptr2 = 0

while ptr1 != len(one) and ptr2 != len(two):
	a = int(input())
	if a == 1:
		place(2, two[ptr2][0], two[ptr2][1])
		ptr2 += 1
	else:
		place(1, one[ptr1][0], one[ptr1][1])
		ptr1 += 1
	count += 1

if ptr1 == len(one):
	while ptr2 != len(two):
		a = int(input())
		if a == 2:
			place(3, two[ptr2][0], two[ptr2][1])
		else:
			place(2, two[ptr2][0], two[ptr2][1])
		ptr2 += 1

else:
	while ptr1 != len(one):
		a = int(input())
		if a == 1:
			place(3, one[ptr1][0], one[ptr1][1])
		else:
			place(1, one[ptr1][0], one[ptr1][1])
		ptr1 += 1

