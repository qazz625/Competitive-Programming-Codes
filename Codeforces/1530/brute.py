t = int(input())
for _ in range(t):
	n = int(input())
	oria = [int(j) for j in input().split()]
	orib = [int(j) for j in input().split()]
	for i in range(100):
		a = oria + [100]*i
		b = orib + [0]*i
		a.sort(reverse=True)
		b.sort(reverse=True)
		scorea = 0
		scoreb = 0
		num = n+i - (n+i)//4
		print(num, n+i, len(a))
		print(a)
		print(b)
		for j in range(num):
			scorea += a[j]
			scoreb += b[j]
		print(scorea, scoreb)
		if scorea >= scoreb:
			print(i)
			break