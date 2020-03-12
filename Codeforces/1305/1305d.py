n = int(input())
arr = [[] for i in range(n)]
for i in range(n-1):
	x, y = map(int, input().split())
	arr[x-1] += [y-1]
	arr[y-1] += [x-1]

q = []
done = [0]*n

for i in range(n):
	if len(arr[i]) == 1:
		q += [i+1]
		done[i] = 1

leaves = q[:]


# print(q)
flag = 0
while len(q) > 1:
	a = q[0]
	b = q[1]
	print("?", a, b, flush=True)
	c = int(input())
	ans = c
	if a in leaves and b in leaves and c in leaves:
		ans = c
		flag = 1
		break

	if c == -1:
		exit()

	# print(q)

	for i in range(n):
		if b-1 in arr[i]:
			arr[i].remove(b-1)
		if a-1 in arr[i]:
			arr[i].remove(a-1)
	arr[a-1] = []
	arr[b-1] = []

	q.remove(a)
	q.remove(b)
	for i in range(n):
		if done[i] == 0 and len(arr[i]) == 1:
			q += [i+1]
			done[i] = 1

	leaves = q[:]
	# print(q)
	# print(*arr)


if flag == 0:
	if len(q) != 0:
		print("!", q[0], flush=True)
	else:
		print("!", ans, flush=True)
else:
	print("!", c, flush=True)