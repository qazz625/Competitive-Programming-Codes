from collections import defaultdict

def assignment(arr):
	s = arr[1]
	count = 0
	for i in range(len(s)-3):
		if s[i:i+4] == 'haha':
			count += 1

	pref = ''
	suff = ''
	for i in range(0, min(len(s), 3)):
		pref += s[i]
	for j in range(max(len(s)-3, 0), len(s)):
		suff += s[j]
	d[arr[0]] = [count, pref, suff]

def concat(arr):
	var = arr[0]
	one = arr[2]
	two = arr[4]
	count = d[one][0] + d[two][0]

	for i in range(min(3, len(d[one][1]))):
		try:
			if d[one][2][i:] + d[two][1][:4-len(d[one][2][i:])] == 'haha':
				count += 1
		except:
			pass

	pref = d[one][1]
	suff = d[two][2];

	ind = 0
	while len(pref) != 3 and ind < len(d[two][1]):
		pref += d[two][1][ind]
		ind += 1

	ind = len(d[one][2])-1
	while len(suff) != 3 and ind >= 0:
		suff = d[one][2][ind] + suff
		ind -= 1

	d[var] = [count, pref, suff]



t = int(input())
for _ in range(t):
	n = int(input())
	d = defaultdict(list)
	for i in range(n):
		s = input()
		if s.split()[1] == ':=':
			assignment(s.split(' := '))
		else:
			concat(s.split())

		if i == n-1:
			print(d[s.split()[0]][0])
