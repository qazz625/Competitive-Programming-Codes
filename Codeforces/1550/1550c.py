import sys

input = sys.stdin.readline

def dist(p1, p2):
	return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	ans = n + n-1

	for i in range(3, 6):
		for j in range(n-i+1):
			temparr = arr[j:j+i]
			temparr2 = [x+1 for x in range(j, j+i)]
			m = len(temparr)
			flag = 0
			for x in range(m):
				for y in range(x+1, m):
					for z in range(y+1, m):
						p1 = (temparr[x], temparr2[x])
						p2 = (temparr[y], temparr2[y])
						p3 = (temparr[z], temparr2[z])
						cond1 = dist(p1, p2) == dist(p1, p3) + dist(p2, p3)
						cond2 = dist(p2, p3) == dist(p1, p3) + dist(p1, p2)
						cond3 = dist(p1, p3) == dist(p2, p3) + dist(p1, p2)
						if cond1 or cond2 or cond3:
							flag = 1
							break
			if flag == 0:
				ans += 1
	print(ans)

