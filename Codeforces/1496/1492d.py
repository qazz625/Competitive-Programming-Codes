a, b, k = map(int, input().split())

if a == 0:
	if k == 0:
		print("Yes")
		print('1'*b)
		print('1'*b)
	else:
		print("No")
	exit()

if k > a:
	print("No")
	exit()

print("Yes")

num1 = '1'*b + '0'*a
num2 = '1'*(b-1) + '0'*k + '1' + '0'*(a-k)

print(num1)
print(num2)