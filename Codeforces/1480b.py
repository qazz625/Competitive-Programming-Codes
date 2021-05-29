t = int(input())
for _ in range(t):
	a, b, n = map(int, input().split())
	attack = [int(j) for j in input().split()]
	health = [int(j) for j in input().split()]

	ans = "YES"
	damage = 0

	for i in range(n):
		fights = health[i]//a
		if health[i]%a != 0:
			fights += 1
		damage += fights*attack[i]

	if damage <= b:
		ans = "YES"

	else:
		m = max(attack)
		if damage-m <= b:
			ans = "YES"
		else:
			ans = "NO"

	print(ans)