# MAX = 1000

# def factorize(n):
# 	ret = []
# 	for i in range(2, n):
# 		if n%i == 0:
# 			ret += [i]
# 	return ret

# arr = [0]*MAX
# arr[1] = 0
# #1 for win
# #0 fo loss
# for i in range(2, MAX):
# 	factors = factorize(i)
# 	for x in factors:
# 		if arr[i-x] == 0:
# 			arr[i] = 1

# for i in range(10, MAX):
# 	print(i, arr[i])
# 	assert i%2 != arr[i]


s = set()
for i in range(1, 40, 2):
	s.add(2**i)

t = int(input())
for _ in range(t):
	n = int(input())
	if n%2 == 1 or n in s:
		print("Bob")
	else:
		print("Alice")