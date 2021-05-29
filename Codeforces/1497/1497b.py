t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	arr = [int(j) for j in input().split()]
	freq = [0]*m

	for x in arr:
		freq[x%m] += 1

	# print(freq)

	ans = 0
	if freq[0] > 0:
		ans += 1

	for i in range(1, m//2+1):
		if freq[i] == 0 or freq[m-i] == 0:
			ans += max(freq[i], freq[m-i])
			continue

		if i == m-i:
			ans += 1
			continue

		if abs(freq[i]-freq[m-i]) > 1:
			ma = max(freq[i], freq[m-i])
			mi = min(freq[i], freq[m-i])

			ans += 1
			ma -= mi
			ma -= 1
			ans += ma
		else:
			ans += 1

	print(ans)
