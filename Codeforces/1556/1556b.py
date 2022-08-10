t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(j) for j in input().split()]

	even = []
	odd = []

	for i in range(n):
		if arr[i]%2 == 0:
			even += [i]
		else:
			odd += [i]

	if n%2 == 0 and len(even) != len(odd):
		print(-1)
		continue
	elif n%2 == 1 and abs(len(even)-len(odd)) != 1:
		print(-1)
		continue

	evenfirst = []
	oddsecond = []

	oddfirst = []
	evensecond = []
	for i in range(n):
		if i%2 == 0:
			evenfirst += [i]
		else:
			oddsecond += [i]

	for i in range(n):
		if i%2 == 0:
			oddfirst += [i]
		else:
			evensecond += [i]

	# print(even)
	# print(odd)

	if n%2 == 0:
		ans1, ans2 = 0, 0

		ptr1, ptr2 = 0, 0
		for i in range(n):
			if arr[i]%2 == 0:
				ans1 += abs(evenfirst[ptr1] - i)
				ptr1 += 1
			else:
				ans1 += abs(oddsecond[ptr2] - i)
				ptr2 += 1

		ptr1, ptr2 = 0, 0
		for i in range(n):
			if arr[i]%2 == 0:
				ans2 += abs(evensecond[ptr1] - i)
				ptr1 += 1
			else:
				ans2 += abs(oddfirst[ptr2] - i)
				ptr2 += 1

		print(min(ans1, ans2)//2)

	elif len(even) > len(odd):
		ans1, ans2 = 0, 0
		ptr1, ptr2 = 0, 0
		for i in range(n):
			if arr[i]%2 == 0:
				ans1 += abs(evenfirst[ptr1] - i)
				ptr1 += 1
			else:
				ans1 += abs(oddsecond[ptr2] - i)
				ptr2 += 1
		print(ans1//2)

	else:
		ans2 = 0
		ptr1, ptr2 = 0, 0
		for i in range(n):
			if arr[i]%2 == 0:
				ans2 += abs(evensecond[ptr1] - i)
				ptr1 += 1
			else:
				ans2 += abs(oddfirst[ptr2] - i)
				ptr2 += 1
		print(ans2//2)




