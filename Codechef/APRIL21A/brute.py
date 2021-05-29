from collections import defaultdict

t = int(input())
for _ in range(t):
	n, m, k = map(int, input().split())
	arr = [int(j) for j in input().split()]

	d = defaultdict(int)

	for i in range(m):
		u, v, val = map(int, input().split())
		d[(u-1, v-1)] = val


	res = []
	for i in range(2**n):
		val = 0
		for j in range(n-1, -1, -1):
			if ((1<<j)&i) > 0:
				val += arr[n-1-j]

		b = bin(i)[2:]
		b = '0'*(n-len(b)) + b
		for x in range(len(b)):
			for y in range(x, len(b)):
				if b[x:y+1].count('1') == len(b[x:y+1]):
					val += d[(x, y)]

		res += [val]

	res.sort(reverse=True)
	print(*res[:k])



