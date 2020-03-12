t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	if arr.count(0) == n:
		print(0)
	else:
		ptr1 = 0
		ptr2 = n-1
		# print(ptr1, ptr2)
		while arr[ptr1] == 0:
			ptr1 += 1
		while arr[ptr2] == 0:
			ptr2 -= 1
		
		print(ptr2-ptr1+1)
