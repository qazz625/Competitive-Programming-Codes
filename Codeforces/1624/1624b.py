from itertools import permutations

t = int(input())
for _ in range(t):
	a = [int(j) for j in input().split()]

	# l = permutations(arr)

	ans = "NO"
	# for a in l:
	one = (2*a[1]-a[2]) > 0 and (2*a[1]-a[2])%a[0] == 0
	two = (2*a[1]-a[0]) > 0 and (2*a[1]-a[0])%a[2] == 0
	three = (a[0]+a[2]) > 0 and (a[0]+a[2])%(2*a[1]) == 0
	if one or two or three:
		# print(a, one, two, three)
		ans = "YES"

	print(ans)