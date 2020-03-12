from math import ceil

n = int(input())
arr1 = [int(j) for j in input().split()]
arr2 = [int(j) for j in input().split()]
ans = [0]*n

for i in range(n):
	if arr1[i] == arr2[i]:
		ans[i] = 1

count1 = 0
for i in range(n):
	if arr1[i] == 0 and arr2[i] == 1:
		count1 += 1
		ans[i] = 1

count2 = 0
for i in range(n):
	if arr1[i] == 1 and arr2[i] == 0:
		count2 += 1

if count1 == 0 and count2 == 0:
	print(-1)

elif count2 == 0:
	print(-1)

else:
	# print(count1, count2)
	if count1%count2 == 0:
		print(count1//count2 + 1)
	else:
		print(ceil(count1/count2))

