t = int(input())
for _ in range(t):
	D, d, P, Q = map(int, input().split())

	add = D//d
	rem = D%d
	ans = (add*P + add*(add-1)//2 * Q)*d
	ans += rem*(P + add*Q)

	print(ans)