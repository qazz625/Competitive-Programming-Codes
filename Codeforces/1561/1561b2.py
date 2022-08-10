t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	n = a+b

	aserve1 = n//2
	bserve1 = n-aserve1

	bserve2 = n//2
	aserve2 = n-bserve2

	minc1 = aserve1 - min(aserve1, a) + bserve1 - min(bserve1, b)
	maxc1 = min(aserve1, b) + min(bserve1, a)


	minc2 = aserve2 - min(aserve2, a) + bserve2 - min(bserve2, b)
	maxc2 = min(aserve2, b) + min(bserve2, a)

	# print(minc1, maxc1)
	# print(minc2, maxc2)
	s = set()
	for i in range(minc1, maxc1+1, 2):
		s.add(i)
	for i in range(minc2, maxc2+1, 2):
		s.add(i)

	ans = list(s)
	ans.sort()
	print(len(ans))
	print(*ans)



