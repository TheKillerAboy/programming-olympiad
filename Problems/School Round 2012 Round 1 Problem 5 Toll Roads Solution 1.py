from itertools import permutations
from itertools import combinations
from string import ascii_uppercase

class Path:
    def __init__(self,path):
        self.path = path
        self.cost = 0
        for start, end in zip(self.path[:-1],self.path[1:]):
            if ascii_uppercase.index(start)>ascii_uppercase.index(end):
                self.cost += connections[(end,start)]
            else:
                self.cost += connections[(start,end)]

    def __repr__(self):
        return ' '.join(list(self.path))+', '+str(self.cost)

if __name__ == '__main__':
    letters = list('ABCDEF')
    connections = {}
    connections_list = [int(_) for _ in input('Input: ').split(', ')]
    for c, combo in enumerate(combinations(letters,2)):
        connections[combo] = connections_list[c]
    prices = []
    for permu in map(lambda path:'A'+''.join(path)+'A',permutations(letters[1:])):
        prices.append(Path(permu))
    print(min(prices,key=lambda path:path.cost))

'''
12, 10, 14, 4, 11, 7, 2, 2, 10, 3, 6, 9, 8, 10, 1
'''