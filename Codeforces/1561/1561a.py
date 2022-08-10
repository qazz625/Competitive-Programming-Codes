t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	sortedarr = arr[:]
	sortedarr.sort()

	if arr == sortedarr:
		print(0)
		continue

	for i in range(1, 2000):
		if i%2 == 0:
			for j in range(1, n-1, 2):
				if arr[j] > arr[j+1]:
					arr[j], arr[j+1] = arr[j+1], arr[j]

		if i%2 == 1:
			for j in range(0, n-2, 2):
				if arr[j] > arr[j+1]:
					arr[j], arr[j+1] = arr[j+1], arr[j]

		if arr == sortedarr:
			print(i)
			break