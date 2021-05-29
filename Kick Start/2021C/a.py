alph = 'abcdefghijklmnopqrstuvwxyz'
mod = 10**9 + 7
t = int(input())
for _ in range(t):
	print("Case #{0}:".format(_+1), end=' ')
	n, k = map(int, input().split())
	s = input()
	arr = [0]*n

	#becomes smaller at i'th position
	flag = 0
	ans = 0
	for i in range(0, n//2):
		# print('i', i)
		if s[i] > alph[k-1]:
			flag = 1
			break
		if n%2 == 0:
			ans += (ord(s[i]) - ord('a')) * pow(k, n//2-1-i, mod)
		else:
			ans += (ord(s[i]) - ord('a')) * pow(k, n//2-i, mod)
		
		arr[i] = s[i]
		arr[n-1-i] = s[i]

	# print(ans)
	# print(arr)
	if n%2 == 1 and flag == 0:
		if s[n//2] <= alph[k-1]:
			ans += (ord(s[n//2]) - ord('a'))
		else:
			flag = 1
		arr[n//2] = s[n//2]
		arr[n-1-n//2] = s[n//2]

	if flag == 0:
		# print(arr)
		news = ''
		for x in arr:
			news += x

		if news < s:
			ans += 1


	print(ans%mod)

#aaaaaa
#aaaaa


