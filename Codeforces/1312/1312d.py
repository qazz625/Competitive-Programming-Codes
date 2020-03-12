n, m = map(int, input().split())
ans = 0
mod = 998244353
l = n-2
for i in range(1, m):
	p = pow(2, i, mod)-1
	num = l
	if num == 0:
		p2 = 1
	else:
		p2 = pow(2, num-1, mod)-2
	ans += (p*p2)%mod
	l -= 1
	print(ans, num)
print(ans)
