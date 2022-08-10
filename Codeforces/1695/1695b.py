t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	if n%2:
		print("Mike")
	else:
		mike = 0
		for i in range(0, n, 2):
			mike += arr[i];

		joe = 0
		for i in range(1, n, 2):
			joe += arr[i]

		if joe >= mike:
			print("Joe")
		else:
			print("Mike")

