from math import log2

s = input()
n = int(s, 2)
count = 0
x = 1
while x < n:
	x *= 4
	count += 1

# if x == n:
# 	count -= 1

print(count)