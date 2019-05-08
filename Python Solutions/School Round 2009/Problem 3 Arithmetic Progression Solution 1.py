from itertools import permutations
import math

class Progression:
    def __init__(self,sequance):
        self.diffrence = sequance[1]-sequance[0]
        self.lenght = 2
        for i in range(1,len(sequance)-1):
            if sequance[i+1]-sequance[i] == self.diffrence:
                self.lenght+=1
            else:
                break
        self.start = sequance[0]

    def __hash__(self):
        return hash((self.diffrence,self.lenght,self.start))

    def __eq__(self, other):
        return hash(self)==hash(other)

    def __repr__(self):
        return f'start: {self.start} difference: {self.diffrence} length: {self.lenght}'

def gcd(ls):
    if len(ls)>2:
        return math.gcd(gcd(ls[:-1]),ls[-1])
    elif len(ls) == 2:
        x,y = tuple(ls)
        return math.gcd(x,y)
    else:
        return ls[0]

if __name__ == '__main__':
    progrssions = set()
    N = int(input('Enter N: '))
    numbers = []
    for _ in range(N):
        numbers.append(int(input('Enter a number: ')))
    for permu in permutations(numbers):
        prog = Progression(permu)
        if prog.diffrence>0:
            progrssions.add(prog)
    max_lenght = max(progrssions,key=lambda prog:prog.lenght).lenght
    progrssions = {prog for prog in progrssions if prog.lenght == max_lenght}
    print(f'Arithmetic Progression Length = {max_lenght}')
    print(f'Number of Arithmetic Progression = {len(progrssions)}')
    print(f'Arithmetic Progression First Term = {min(progrssions,key=lambda prog:prog.start).start}')
    print(f'Arithmetic Progression Common Difference = {gcd(list(map(lambda prog:prog.diffrence,progrssions)))}')

'''
Enter N: 10
Enter a number: 1
Enter a number: 4
Enter a number: 9
Enter a number: 16
Enter a number: 25
Enter a number: 36
Enter a number: 49
Enter a number: 64
Enter a number: 81
Enter a number: 100
'''