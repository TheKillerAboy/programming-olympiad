from random import randint
import os 

testcases = 100
out = []
for i in range(testcases):
	out.append(randint(0,testcases))
left = randint(0,testcases-1)
tackSearch = sum(out[left:randint(left+1,testcases)])
data = ''
data += f'{tackSearch} {testcases}' + '\n'
for val in out:
	data += str(val) + '\n'
print(data)