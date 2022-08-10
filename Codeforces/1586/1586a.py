def isComposite(n):
	for i in range(2, n):
		if n%i == 0:
			return True
	return False


t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	s = sum(arr)

	if isComposite(s):
		print(n)
		ans = [i+1 for i in range(n)]
		print(*ans)
		continue


	for i in range(n):
		if isComposite(s - arr[i]):
			print(n-1)
			first = [i+1 for i in range(0, i)]
			second = [i+1 for i in range(i+1, n)]
			print(*(first+second))
			break
