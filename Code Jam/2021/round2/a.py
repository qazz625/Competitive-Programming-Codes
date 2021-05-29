from random import shuffle
from math import ceil
# arr = [i for i in range(1, 101)]

# shuffle(arr)

# print(arr)

# tot = 0
# for i in range(1, 101):
# 	tot += ceil(10**8/i)
# print(tot)
# print(len(str(tot)))

def ask(c, a, b):
	print(c, a+1, b+1, flush=True)


t, n = map(int, input().split())
for _ in range(t):
	# for i in range(1000):
	# 	ind1 = random.randint(0, n-2)
	# 	ind2 = random.randint(ind1+1, n-1)
	# 	ask('S', ind1, ind2)

	for i in range(n-1):
		ask('M', i, n-1)
		pos = int(input())
		assert pos != -1
		if pos-1 != i:
			ask('S', i, pos-1)
			verify = int(input())

	print('D', flush=True)
	verify = int(input())
	assert verify == 1
