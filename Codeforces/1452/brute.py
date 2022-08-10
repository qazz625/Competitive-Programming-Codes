import heapq

mod = 998244353

n = int(input())
arr = []
for _ in range(n):
	inp = input().split()
	if len(inp) == 2:
		inp[1] = int(inp[1])

	arr += [inp]

ans = 0
for i in range(1<<n):
	curarr = []
	for j in range(n):
		if i&(1<<j):
			curarr += [arr[j]]

	# print(curarr)
	li = []
	heapq.heapify(li)

	for x in curarr:
		if x[0] == '-' and len(li) != 0:
			heapq.heappop(li)
		elif x[0] == '+':
			heapq.heappush(li, x[1])

	ans += sum(list(li))

print(ans%mod)


