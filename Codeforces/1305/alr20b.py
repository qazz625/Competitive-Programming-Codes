def PolygonArea(corners):
    n = len(corners) # of corners
    area = 0
    for i in range(n):
        j = (i + 1) % n
        area += corners[i][0] * corners[j][1]
        area -= corners[j][0] * corners[i][1]
    area = abs(area)//2
    return area

t = int(input())
for _ in range(t):
	s = input()
	arr = [0]*len(s)
	x, y = 0, 0
	for i in range(len(s)):
		if s[i] == "R":
			x += 1
		elif s[i] == "L":
			x -= 1
		elif s[i] == "U":
			y += 1
		else:
			y -= 1

		arr[i] = [x, y]

	# print(arr)j

	arr.pop()

	# print(*arr)
	print(PolygonArea(arr))
