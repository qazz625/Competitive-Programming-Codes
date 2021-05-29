import sys

arr = []
for i in range(31):
	arr += [1<<i]

# print(arr)

t = int(sys.stdin.readline().strip())
for _ in range(t):
	n = int(sys.stdin.readline().strip())
	ans = -1
	for x in arr:
		if x <= n:
			ans = x
	print(ans-1)
