t = int(input())
final = []
for i in range(t):
	n, k = map(int, input().split())
	s = input()
	s = list(s)
	zero = []
	for i in range(n):
		if s[i] == '0':
			zero += [i]

	ind = 0
	lol = 0
	for x in zero:
		if x-lol > k:
			break

		temp = s[x]
		s[x] = s[lol]
		s[lol] = temp

		k -= (x - lol)
		ind += 1
		lol += 1
		# print(s)
 
	# print(ind, zero)
	if ind == len(zero):
		# ans = ''
		for x in s:
			print(x, end='')
		print('')
		# final += [ans]
		continue

	ind = zero[ind]
	# while k != 0:
	temp = s[ind]
	s[ind] = s[ind-k]
	s[ind-k] = temp
		# k -= 1
		# ind -= 1

	for x in s:
		print(x, end='')
	print('')
	# final += [ans]
	# print(final)

# print(*final, sep='\n')

	# print(s)

	# print(zero)