from random import shuffle
from math import ceil
from sys import stderr

n = 100
t = 100

print(t, n)
for i in range(t):
	arr = [i for i in range(1, 101)]
	shuffle(arr)
	tot = 0
	while True:
		q = input().split()
		if len(q) == 1 and q[0] == 'D':
			break

		# stderr.write(str(q) + "\n")


		ch = q[0]
		ind1 = int(q[1])
		ind2 = int(q[2])

		if ch == 'M':
			pos = -1
			mi = 10**8
			tot += ceil(10**8/(ind2-ind1+1))
			for i in range(ind1-1, ind2-1):
				if arr[i] < mi:
					mi = arr[i]
					pos = i

			assert pos != -1
			print(pos)
		else:
			arr[ind1-1], arr[ind2-1] = arr[ind2-1], arr[ind1-1]


	sortedarr = arr[:]
	sortedarr.sort()
	if arr == sortedarr:
		print(-1)
	else:
		print(1)

	assert tot < 6*10**8
	stderr.write(str(tot) + "\n")
