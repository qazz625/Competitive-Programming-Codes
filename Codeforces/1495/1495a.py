t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	s = input()
	if n%2 == 0 and k == n//2:
		print("NO")
		continue

	ind = 0
	while ind != k and s[ind] == s[-1-ind]:
		ind += 1

	# print(ind)

	if ind >= k:
		print("YES")
	else:
		print("NO")

