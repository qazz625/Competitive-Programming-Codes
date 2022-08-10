t = int(input())
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
primes = set(primes)
for _ in range(t):
	n = int(input())
	s = input()

	ans = 0
	for i in range(n):
		if int(s[i]) not in primes:
			ans = s[i]

	if ans != 0:
		print(1)
		print(ans)
		continue

	for i in range(n):
		for j in range(i+1, n):
			if int(s[i]+s[j]) not in primes:
				ans = s[i]+s[j]

	print(2)
	print(ans)
	assert ans != 0

