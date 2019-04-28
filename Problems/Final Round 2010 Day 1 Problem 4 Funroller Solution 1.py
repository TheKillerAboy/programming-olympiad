class ride:
	def __init__(self,path,height,up,down):
		self.path = path
		self.height = height
		self.up=up
		self.down = down
	def next(self):
		if self.height<amount/2 and self.up>0:
			yield ride([*self.path,1],self.height+1,self.up-1,self.down)
		if self.height>0 and self.down>0:
			yield ride([*self.path,-1],self.height-1,self.up,self.down-1)
	def valid(self):
		valid = self.height == 0
		valid = valid and self.path[:int(amount/2)]!=[-1*i for i in self.path[int(amount/2):][::-1]]
		return valid

amount = int(input())*2

rides = [ride([],0,amount/2,amount/2)]

for _ in range(amount):
	copy =rides.copy();
	rides.clear()
	for cost in copy:
		for new in cost.next():
			rides.append(new)
		
counter = 0
for cost in rides:
	if cost.valid():
		counter+=1
	
print(counter)
	
	

	
	
	

