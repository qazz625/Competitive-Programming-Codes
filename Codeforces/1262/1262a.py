

t = int(input())
for i in range(t):
	arr1 = []
	arr2 = []
	n = int(input())
	for j in range(n):
		l, r = map(int, input().split())
		arr1 += [[l, r]]
		arr2 += [[r, l]]
 
	arr2.sort()
	arr1.sort(reverse=True)
 
	left = arr2[0][0]
	right = arr1[0][0]
 
	if left >= right:
		print(0)
 
	else:
		print(right-left)