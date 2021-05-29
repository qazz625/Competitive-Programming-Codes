t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	arr.sort()
	ans = 0
	flag = 0
	for i in range(n):
		if arr[i] > i+1:
			flag = 1
			break
		ans += i+1 - arr[i]

	if ans%2 == 1:
		print("First")
	else:
		print("Second")
