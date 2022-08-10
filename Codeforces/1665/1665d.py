def ask(a, b):
	print('?', a, b, flush=True)

t = int(input())
for _ in range(t):

	a = 1
	b = (1<<30) + 1
	while a <= 2*10**9 and b <= 2*10**9:
		ask(a, b)
		n = int(input())
		a += n
		b += n

	a -= n

	print('!', n-a, flush=True)

