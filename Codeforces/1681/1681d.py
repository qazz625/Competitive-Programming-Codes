n, x = map(int, input().split())

dp = [[-1 for i in range(1023)] for j in range(20)]


l = len(str(x))
values = 0
for num in str(x):
	values |= 1<<int(num)

print(bin(values)[2:])

dp[l][values] = 0
for i in range(l, n):
	for j in range(1<<10):
		for k in range(1, 10):
			