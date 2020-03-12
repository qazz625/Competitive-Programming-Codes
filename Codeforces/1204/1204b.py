n, l, r = map(int, input().split())
x = 1
mi = []

for i in range(l):
	mi += [x]
	x *= 2

for i in range(l, n):
	mi += [1]

# print(sum(mi))

ma = []
x = 1
for i in range(r):
	ma += [x]
	x *= 2
x //= 2
for i in range(r, n):
	ma += [x]

print(sum(mi), sum(ma))