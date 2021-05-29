t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	temp = arr[:]
	temp.sort()
	if temp == arr:
		print(0)
	elif arr[0] == 1 or arr[-1] == n:
		print(1)
	elif arr[0] != n or arr[-1] != 1:
		print(2)
	else:
		print(3)
