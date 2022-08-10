t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	freq = [0]*1000000
	for i in range(m+1):
		freq[i^n] = 1

	for i in range(1000000):
		if freq[i] == 0:
			print(i)
			break