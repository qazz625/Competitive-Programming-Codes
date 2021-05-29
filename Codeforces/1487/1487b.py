t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	if n%2 == 0:
		ans = k%n
		if k%n == 0:
			ans = n
		print(ans)
		continue


	start = 2*(k//n) % n
	rem = (k-1)%n

	print(start, rem)

