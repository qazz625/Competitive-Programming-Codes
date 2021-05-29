t = int(input())
for _ in range(t):
	n, k1, k2 = map(int, input().split())
	w, b = map(int, input().split())

	maxwhite = (k1+k2)//2

	maxblack = (n-k1 + n-k2)//2

	if w <= maxwhite and b <= maxblack:
		print("YES")
	else:
		print("NO")