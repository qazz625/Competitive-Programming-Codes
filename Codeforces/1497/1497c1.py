t = int(input())
for _ in range(t):
	n, k = map(int, input().split())

	if n == k:
		print(*([1]*n))
		continue

	elif n-1 == k:
		print(*([1]*(k-1) + [2]))
		continue

	elif n-2 == k:
		print(*([1]*(k-2) + [2, 2]))
		continue

	ans = [1]*(k-3)
	n -= k-3

	if n%2 == 1:
		ans += [1, (n-1)//2, (n-1)//2]

	elif n%4 == 0:
		ans += [n//4, n//4, n//2]

	else:
		ans += [2, n//2-1, n//2-1]

	print(*ans)