s = input()
space_split = s.split()
for x in space_split:
	curword = x.split('-')
	if len(curword) == 2 and curword[0].isnumeric() and curword[1] == "Year":
		print(curword)


  is_auction_present = "Auction" in desc
  year = ""
  for x in desc.split(' '):
    temp = x.split('-')
    if len(temp) > 1 and temp[1] == 'Year' and is_auction_present:
      	year = temp[0]
  return year

0000  
0001
0010
0011
0100
0101
0110
0111

1000  
1001
1010
1011
1100
1101
1110
1111

n*(n - 2) / 8

n/4 groups
n/2-1 or 0 sum

n/4 *(n/2 - 1)