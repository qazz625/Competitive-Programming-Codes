from sys import stdin
input = stdin.readline

n = int(input())
xarr = []
yarr = []
for _ in range(n):
	x, y = map(int, input().split())
	xarr += [[x, y, _]]
	yarr += [[y, x, _]]

xarr.sort()
yarr.sort()

xdist1 = (max(abs(xarr[-1][0]-xarr[0][0]), abs(xarr[-1][1]-xarr[0][1])), min(xarr[-1][2], xarr[0][2]), max(xarr[-1][2], xarr[0][2]))
xdist2 = (max(abs(xarr[-2][0]-xarr[0][0]), abs(xarr[-2][1]-xarr[0][1])), min(xarr[-2][2], xarr[0][2]), max(xarr[-2][2], xarr[0][2]))
xdist3 = (max(abs(xarr[-1][0]-xarr[1][0]), abs(xarr[-1][1]-xarr[1][1])), min(xarr[-1][2], xarr[1][2]), max(xarr[-1][2], xarr[1][2]))

ydist1 = (max(abs(yarr[-1][0]-yarr[0][0]), abs(yarr[-1][1]-yarr[0][1])), min(xarr[-1][2], xarr[0][2]), max(yarr[-1][2], yarr[0][2]))
ydist2 = (max(abs(yarr[-2][0]-yarr[0][0]), abs(yarr[-2][1]-yarr[0][1])), min(xarr[-2][2], xarr[0][2]), max(yarr[-2][2], yarr[0][2]))
ydist3 = (max(abs(yarr[-1][0]-yarr[1][0]), abs(yarr[-1][1]-yarr[1][1])), min(xarr[-1][2], xarr[1][2]), max(yarr[-1][2], yarr[1][2]))

# print(xdist1, xdist2, xdist3)
# print(ydist1, ydist2, ydist3)

s = set()
s.add(xdist1)
s.add(xdist2)
s.add(xdist3)
s.add(ydist1)
s.add(ydist2)
s.add(ydist3)

s = list(s)
s.sort()

# print(s)

print(s[-2][0])