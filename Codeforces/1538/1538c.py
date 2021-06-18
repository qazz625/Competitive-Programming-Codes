import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
	n, l, r = map(int, input().split())
	arr = [int(j) for j in input().split()]

	arr.sort()

	ans = 0
	for i in range(n):
		s, e, ans1 = i+1, n-1, -1
		while s <= e:
			mid = (s+e)//2
			if arr[mid] + arr[i] >= l:
				ans1 = mid
				e = mid-1
			else:
				s = mid+1

		s, e, ans2 = i+1, n-1, -1
		while s <= e:
			mid = (s+e)//2
			if arr[mid] + arr[i] <= r:
				ans2 = mid
				s = mid+1
			else:
				e = mid-1

		if ans1 != -1 and ans2 != -1:
			ans += ans2-ans1+1

	print(ans)

