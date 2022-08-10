def ask1(n):
	print("? 1", n, flush=True)

def ask2(l, r):
	print("? 2", l, r, flush=True)

alphabets = "abcdefghijklmnopqrstuvwxyz"

n = int(input())
ans = [0]*(n+1)

chars = [0]*26

ask1(1)
ans[1] = input()
chars[ord(ans[1]) - ord('a')] = 1


cur = 1
for i in range(2, n+1):
	ask2(1, i)
	inp = int(input())
	if inp != cur:
		cur += 1
		ask1(i)
		ans[i] = input()
		chars[ord(ans[i]) - ord('a')] = i


for i in range(1, n+1):
	if ans[i] == 0:
		temp = []
		for j in range(26):
			if chars[j] != 0:
				temp += [[chars[j], alphabets[j]]]
		temp.sort()

		for j in range(len(temp)):
			if temp[j][0] <= i:
				end = j

		iniend = end

		start = 0
		binans = -1
		while start <= end:
			mid = (start+end)//2
			ask2(temp[mid][0], i)
			inp = int(input())
			if inp != iniend-mid+2:
				binans = mid
				start = mid+1
			else:
				end = mid-1

		assert binans != -1

		ans[i] = temp[binans][1]
		chars[ord(ans[i]) - ord('a')] = i


s = ''
for i in range(1, n+1):
	s += ans[i]
print('!', s, flush=True)
# print(ans)
# print(chars)

