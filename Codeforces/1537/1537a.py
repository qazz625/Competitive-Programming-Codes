t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	su = sum(arr)
	k = len(arr)
	if su < k:
		print(1)
	elif su == k:
		print(0)
	else:
		print(su-k)