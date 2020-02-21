t = int(input())
for _ in range(t):
	A, B = map(int, input().split())
	B = str(B)
	if B.count('9') == len(B):
		l = len(B)
	else:
		l = len(B)-1
	print(A*l)