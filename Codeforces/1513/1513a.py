t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	arr = [i for i in range(1, n+1)]

	if n%2 == 0 and k >= n//2:
		print(-1)
		continue
	if n%2 == 1 and k > n//2:
		print(-1)
		continue

	if k == 0:
		print(*arr)
		continue

	# print(arr)

	ans = []
	for i in range(0, n//2):
		ans += [arr[i]]
		ans += [arr[-1-i]]

	# print(ans)
	if n%2 == 1:
		ans += [n//2 + 1]

	ans2 = []
	for i in range(2*k):
		ans2 += [ans[i]]

	# print(ans2)

	# if n%2 == 0:
	sw = -1
	# else:
	# 	sw = -2

	ans2[1], ans2[sw] = ans2[sw], ans2[1]

	# print(ans2)

	temp = []
	temp = ans[2*k:]
	temp.sort()
	ans2 = ans2 + temp

	print(*ans2)


