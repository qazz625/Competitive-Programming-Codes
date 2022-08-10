t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	seq = [int(j) for j in input().split()]
	arr = ['B']*m

	for i in range(n):
		seq[i] = min(seq[i], m+1-seq[i])
		if arr[seq[i]-1] == 'A':
			seq[i] = m+1-seq[i]
		arr[seq[i]-1] = 'A'

	print(*arr, sep='')