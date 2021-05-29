n, q, k = map(int, input().split())
arr = [0] + [int(j) for j in input().split()] + [k+1]

poss = [0]*(n+2)

for i in range(1, n+1):
	poss[i] = arr[i+1] - arr[i-1] - 1

pref = [0]*(n+2)
for i in range(1, n+1):
	pref[i] = pref[i-1] + poss[i]

for _ in range(q):
	l, r = map(int, input().split())
	ans = -(r-l+1)
	if l == r:
		ans += k
	else:
		l += 1
		r -= 1
		if r >= l:
			ans += pref[r] - pref[l-1]
		ans += arr[l] - 0 - 1
		ans += k+1 - arr[r] - 1
	print(ans)
