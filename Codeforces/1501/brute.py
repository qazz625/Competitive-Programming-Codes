n = int(input())
arr = [int(j) for j in input().split()]

for i in range(n):
	for j in range(n):
		for k in range(n):
			for l in range(n):
				if arr[i] + arr[j] == arr[k] + arr[l] and len(set(i, j, k, l)) == 4:
					print(i+1, j+1, k+1, l+1)
					exit()