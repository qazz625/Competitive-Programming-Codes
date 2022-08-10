t = int(input())
arr = []
cur = 1
while len(arr) != 1010:
	if cur%3 == 0 or cur%10 == 3:
		cur += 1
		continue
	else:
		arr += [cur]
	cur += 1
for _ in range(t):
	n = int(input())
	print(arr[n-1])
