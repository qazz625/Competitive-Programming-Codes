t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]
	mi = min(arr)
	ma = max(arr)

	indmi = arr.index(min(arr))
	indma = arr.index(max(arr))

	# print(indmi, indma)

	one = abs(indmi-indma)-1
	two = min(indmi, indma)
	three = n-1-max(indmi, indma)

	# print(one, two, three)

	print(n-max(one, two, three))