t = int(input())
for _ in range(t):
	n = int(input())
	if bin(n)[2:].count('1') == 1 and n != 1:
		print("YES")
	else:
		print("NO")