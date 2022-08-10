def ask(arr):
	print('?', *arr, flush=True)

n = int(input())
ans = [0]*n

ans[-1] = n
for i in range(1, n+1):
	q = [i]*(n-1) + [n]
	ask(q)
	inp = int(input())
	if inp != 0:
		ans[-1] = i
		break

#find less than last
for i in range(2, ans[-1]+1):
	q = [i]*(n-1) + [1]
	ask(q)
	inp = int(input())
	assert inp != 0
	ans[inp-1] = ans[-1] - i + 1

#find greaater than last
for i in range(2, n-ans[-1]+2):
	q = [1]*(n-1) + [i]
	ask(q)
	inp = int(input())
	assert inp != 0
	ans[inp-1] = ans[-1] + i - 1

print('!', *ans, flush=True)