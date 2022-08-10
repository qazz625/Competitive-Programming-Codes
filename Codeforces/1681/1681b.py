t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	m = int(input())
	shuffles = [int(j) for j in input().split()]

	ptr = 0
	for x in shuffles:
		ptr += x
		ptr %= n
	print(arr[ptr])