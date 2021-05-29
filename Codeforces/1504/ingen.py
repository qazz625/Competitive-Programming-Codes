from random import randint

t = 100000
print(t)
for _ in range(t):
	print(len(bin(_)[2:]))
	print(bin(_)[2:])

