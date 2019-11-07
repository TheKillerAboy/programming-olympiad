from itertools import combinations

class Progression:
    def __init__(self,prog):
        self.common_diffrence = prog[1]-prog[0]
        self.isProgression = True
        for before, after in zip(prog[:-1],prog[1:]):
            if after - before != self.common_diffrence:
                self.isProgression = False
        self.firstTerm = prog[0]
        self.length = len(prog)

if __name__ == '__main__':
    amount = int(input(''))
    progres = []
    for _ in range(amount):
        progres.append(int(input('')))
    longest = []
    length = 0
    for i in range(2,len(progres)+1):
        for progression in map(Progression,map(sorted,combinations(progres,i))):
            if progression.isProgression:
                if progression.length > length:
                    longest = [progression]
                    length = progression.length
                elif progression.length == length:
                    longest.append(progression)
    print(f'Arithmetic Progression Length = {length}')
    print(f'Number of Arithmetic Progression = {len(longest)}')
    print(f'Arithmetic Progression First Term = {min(longest,key=lambda prog:prog.firstTerm).firstTerm}')
    print(f'Arithmetic Progression Common Difference = {min(longest,key = lambda prog:(prog.firstTerm,prog.common_diffrence)).common_diffrence}')

'''
Only sorted progressions are always have a positive difference, so that fact is what speeds this process up
we look thought every combination of the base progression with all sizes and check which is the best and largest
'''