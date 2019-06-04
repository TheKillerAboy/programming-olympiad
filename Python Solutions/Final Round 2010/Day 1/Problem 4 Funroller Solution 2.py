amount = int(input(''))
totalpaths = 0
inner = 0
inner_index = -1
prev = [1 for _ in range(amount+1)]
for i in range(amount-1):
	new = [prev[0]]
	if abs(inner_index)<=len(prev):
		inner+=prev[inner_index]
		inner_index-=1
	if amount%2 == 0:
		if abs(inner_index)==len(prev):
			inner+=prev[inner_index]
			inner_index-=1
	for j in range(1,amount-i):
		new.append(new[j-1])
		new[-1]=(new[-1]+prev[j])%4993
	prev = new[1:]

k = prev[0]-inner%4993
while k < 0:
	k+=4993
print(k)
