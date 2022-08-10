t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(j) for j in input().split()]
	m = int(input())
	b = [int(j) for j in input().split()]

	alice = max(a)
	bob = max(b)

	if alice > bob:
		print("Alice")
		print("Alice")
	elif bob > alice:
		print("Bob")
		print("Bob")
	else:
		print("Alice")
		print("Bob")