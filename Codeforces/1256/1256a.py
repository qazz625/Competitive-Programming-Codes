t = int(input())
for _ in range(t):
	a, b, n, s = map(int, input().split())
 
	maxn = n*a
	if maxn >= s:
 
 
		nnum = s//n
 
		onum = (s%n)
 
		if nnum <= a and onum <= b:
			print("YES")
			# print(nnum, onum)
			# print(nnum*n + onum*1)
		else:
			print("NO") 
 
	else:
		s -= maxn
		nnum = a
		onum = s
 
		if nnum <= a and onum <= b:
			print("YES")
			# print(nnum, onum)
			# print(nnum*n + onum*1)
		else:
			print("NO") 