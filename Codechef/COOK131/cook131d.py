def ask(n):
	print('?', n+1, flush=True)

n = int(input())
changed = [[-1 for i in range(n)] for j in range(n)]

for i in range(n):
	changed[i][i] = 0


ans = [[0 for i in range(n)] for j in range(n)]

known = []
ask(0)
known += [input()]

for i in range(1, n):
	ask(i)
	known += [input()]
	expected = known[:]
	for j in range(i):
		ask(j)
		inp = input()

		#edge exists flip all related to this
		if expected[j] != inp:
			ans[i][j] = 1
			ans[j][i] = 1
			expected[j] = inp

		for k in range(n):
			if ans[j][k] == 1:
				if expected[k] == 'W':
					expected[k] = 'B'
				else:
					expected[k] = 'W'
	known = expected[:]

print('!')
for x in ans:
	print(*x, sep='')
print('', flush=True)
