t = int(input())
for _ in range(t):
	n = int(input())
	s1 = input()
	s2 = input()

	done = [0]*n
	ans = 0
	for i in range(n):
		# print('l', i, s1, s2)
		if done[i] == 1:
			continue
			
		# print(ans, s1[i], s2[i], i)
		if s1[i] == '0' and s2[i] == '1':
			ans += 2
			done[i] = 1
		elif s1[i] == '1' and s2[i] == '0':
			ans += 2
			done[i] = 1
		elif s1[i] == '0' and s2[i] == '0':
			if i-1 >= 0 and s1[i-1] == '1' and s2[i-1] == '1' and done[i-1] == 0:
				ans += 2
				done[i-1] = 1
				done[i] = 1
			elif i+1 < n and s1[i+1] == '1' and s2[i+1] == '1' and done[i+1] == 0:
				ans += 2
				done[i+1] = 1
				done[i] = 1
			else:
				ans += 1

		else:
			# print("AA")
			if i-1 >= 0 and s1[i-1] == '0' and s2[i-1] == '0' and done[i-1] == 0:
				ans += 1
				done[i-1] = 1
				done[i] = 1
			elif i+1 < n and s1[i+1] == '0' and s2[i+1] == '0' and done[i+1] == 0:
				ans += 2
				done[i+1] = 1
				done[i] = 1
			else:
				ans += 0

	print(ans)
