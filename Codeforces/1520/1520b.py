t = int(input())
arr = []
for i in range(1, 12):
	for j in range(10):
		arr += [int(str(j)*i)]

# print(arr)

for _ in range(t):
	n = int(input())
	ans = 0
	for x in arr:
		if x != 0 and x <= n:
			ans += 1
	print(ans)