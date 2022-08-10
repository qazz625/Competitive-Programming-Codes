from collections import defaultdict

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	s = input()

	zero = s.count('0')

	likes = []
	dislike = []
	for i in range(n):
		if s[i] == '1':
			likes += [arr[i]]
		else:
			dislike += [arr[i]]

	likes.sort()
	dislike.sort()

	d = defaultdict(int)
	for i in range(1, zero+1):
		d[dislike[i-1]] = i

	for i in range(zero+1, n+1):
		d[likes[i-zero-1]] = i

	# print(d)

	ans = [0]*n
	for i in range(n):
		ans[i] = d[arr[i]]

	print(*ans)


