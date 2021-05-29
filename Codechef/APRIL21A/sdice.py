class dice:
	def __init__(self):
		self.front = 1
		self.back = 6
		self.left = 5
		self.right = 2
		self.top = 3
		self.bottom = 4

	def rotate_up(self):
		arr = [self.front, self.top, self.back, self.bottom]
		self.top = arr[0]
		self.back = arr[1]
		self.bottom = arr[2]
		self.front = arr[3]

	def rotate_right(self):
		arr = [self.front, self.right, self.back, self.left]
		self.right = arr[0]
		self.back = arr[1]
		self.left = arr[2]
		self.front = arr[3]


possible = []
def generate(arr, n, ind):
	global possible
	if ind == 4:
		if n == sum(arr):
			possible += [arr[:]]
		return

	for i in range(n+1):
		arr[ind] = i
		generate(arr, n, ind+1)


def calculate(dicelist, arr):
	#0 is front left
	#1 is front right
	#2 is back left
	#3 is back right
	pips = 0
	offset = 0
	totarea = 0
	for i in range(arr[0]):
		pips += dicelist[offset+i].left
		totarea += 1
		pips += dicelist[offset+i].front
		totarea += 1
		if i == arr[0]-1:
			pips += dicelist[offset+i].top
			totarea += 1
		if i >= arr[1]:
			pips += dicelist[offset+i].right
			totarea += 1
		if i >= arr[2]:
			pips += dicelist[offset+i].back
			totarea += 1
	offset += arr[0]

	for i in range(arr[1]):
		pips += dicelist[offset+i].right
		totarea += 1
		pips += dicelist[offset+i].front
		totarea += 1
		if i == arr[1]-1:
			pips += dicelist[offset+i].top
			totarea += 1
		if i >= arr[0]:
			pips += dicelist[offset+i].left
			totarea += 1
		if i >= arr[3]:
			pips += dicelist[offset+i].back
			totarea += 1
	offset += arr[1]

	for i in range(arr[2]):
		pips += dicelist[offset+i].left
		totarea += 1
		pips += dicelist[offset+i].back
		totarea += 1
		if i == arr[2]-1:
			pips += dicelist[offset+i].top
			totarea += 1
		if i >= arr[0]:
			pips += dicelist[offset+i].front
			totarea += 1
		if i >= arr[3]:
			pips += dicelist[offset+i].right
			totarea += 1
	offset += arr[2]

	for i in range(arr[3]):
		pips += dicelist[offset+i].right
		totarea += 1
		pips += dicelist[offset+i].back
		totarea += 1
		if i == arr[3]-1:
			pips += dicelist[offset+i].top
			totarea += 1
		if i >= arr[2]:
			pips += dicelist[offset+i].left
			totarea += 1
		if i >= arr[1]:
			pips += dicelist[offset+i].front
			totarea += 1
	offset += arr[3]

	return (totarea, -pips)



ans = (10000, 10000)
def generated(dicelist, ind, arr):
	global ans
	if ind == -1:
		a = calculate(dicelist, arr)
		ans = min(ans, a)
		return

	generated(dicelist, ind-1, arr)
	for i in range(4):
		for j in range(4):
			dicelist[ind].rotate_up()
			generated(dicelist, ind-1, arr)
		dicelist[ind].rotate_right()

def check(arr):
	dicelist = []
	for i in range(n):
		d = dice()
		dicelist += [d]
	generated(dicelist, n-1, arr)

n = int(input())
arr = [0, 0, 0, 0]
generate(arr, n, 0)

print(*possible)

for poss in possible:
	print(poss)
	check(poss)

print(ans)


# 1 -> 20
# 2 -> 36
# 3 -> 50
# 4 -> 60
# 5 -> 76
# 6 -> 96






