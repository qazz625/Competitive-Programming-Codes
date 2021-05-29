import random

t = 2000
x = 14600
print(t)
print(x)
for _ in range(t//4):
	g = random.randint(5, 95)
	w = 10*g

	print(w, w)
	print(w, w//2)
	print(w, w//10)
	print(w, 0)

