t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	ans = -1
	if n == 1 and arr[0]%2 == 1:
		print(-1)
		continue

	for i in range(n):
		if arr[i]%2 == 0:
			ans = i+1
			break

	if ans != -1:
		print(1)
		print(ans)
		continue

	for i in range(n):
		if arr[i]%2 == 1:
			one = i+1
			ind = i+1
			break

	for i in range(ind, n):
		if arr[i]%2 == 1:
			two = i+1
			break

	print(2)
	print(one, two)







