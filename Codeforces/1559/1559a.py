t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	ans = 0
	for j in range(35):
		flag = 0;
		for i in range(n):
			if (arr[i]&(1<<j)) == 0:
				flag = 1
		if flag == 0:
			ans += 1<<j

	print(ans)