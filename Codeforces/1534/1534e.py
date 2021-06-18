def ask(arr):
	print('?', end=' ')
	for x in arr:
		print(x+1, end=' ')
	print('', flush=True)

n, k = map(int, input().split())
if n%k == 0:
	ans = 0
	for i in range(0, n, k):
		ask([j for j in range(i, i+k)])
		ans ^= int(input())
	print('!', ans, flush=True)
	exit()




if n%k%2 == 0:
	ans = 0
	ask([j for j in range(0, k)])
	ans ^= int(input())
	ask([j for j in range(n%k//2, n%k//2+k)])
	ans ^= int(input())

	arr = []
	for i in range(n):
		if (i >= n%k//2 and i < k) or i >= n%k//2 + k:
			arr += [i]
		if len(arr) == k:
			ask(arr)
			ans ^= int(input())
			arr = []
	print('!', ans, flush=True)

elif n%k%2 == 1 and k%2 == 0:
	print(-1, flush=True)

else:
	if k == n-1:
		ans = 0
		for i in range(0, n):
			arr1 = [i for i in range(i)]
			arr2 = [i for i in range(i+1, n)]
			ask(arr1+arr2)
			ans ^= int(input())
		print('!', ans, flush=True)
		exit()
	elif n < 2*k:
		print(-1, flush=True)
		exit()
	
	ans = 0
	rem = k+n%k
	ind = n-1
	for i in range(rem//(k-1)):
		ask([0]+[i for i in range(ind, ind-(k-1), -1)])
		ans ^= int(input())
		ind -= k-1
		rem -= k-1

	if rem > 0:
		arr1 = [i for i in range(ind, ind-rem, -1)]
		ask([i for i in range(k-len(arr1))] + arr1)
		ans ^= int(input())

	for i in range(0, n-(k+n%k), k):
		ask([j for j in range(i, i+k)])
		ans ^= int(input())

	print('!', ans, flush=True)







