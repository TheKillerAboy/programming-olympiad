KnightMovement = [(1,2),(2,1),(-1,2),(-2,1),(-2,-1),(-1,-2),(1,-2),(2,-1)]

class KnightBlock:
    def __init__(self,location):
        self.location = location
        self.helping = 0
        self.help = set()

    def __hash__(self):
        return self.location.__hash__()

    def __eq__(self, other):
        return self.location == other.location

    def clear(self):
        self.helping = 0
        self.help = set()

    def helped(self,ufo):
        self.helping+=1
        self.help.add(ufo)

class UFO:
    def __init__(self,location):
        self.location = Coor(location)

    def KnightMoves(self):
        for offset in KnightMovement:
            yield self.location+offset

    def __eq__(self, other):
        return self.location == other.location

    def __hash__(self):
        return hash(self.location.totuple())

class Coor:
    def __init__(self, location):
        self.x = location[0]
        self.y = location[1]

    def __add__(self, other):
        if type(other) is Coor:
            return Coor((self.x+other.x,self.y+other.y))
        elif type(other) is tuple:
            x, y = other
            return Coor((self.x+x,self.y+y))

    def totuple(self):
        return (self.x,self.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash(self.totuple())

    def __lt__(self, other):
        return other.x>=self.x and other.y >= self.y

    def __gt__(self, other):
        return other.x<=self.x and other.y <= self.y

    def __repr__(self):
        return "{} {}".format(*self.totuple())

MAX = Coor((4, 4))
MIN = Coor((1,1))

if __name__ == '__main__':
    amount = int(input(''))
    Original_ufos = set()
    ufos = set()
    knightblocks = []
    for _ in range(amount):
        ufo = UFO([int(_) for _ in input('').split(' ')])
        if ufo.location > MAX:
            MAX = ufo.location
        if ufo.location < MIN:
            MIN = ufo.location
        ufos.add(ufo)
        Original_ufos.add(ufo)
    for ufo in ufos:
        for knightblock in ufo.KnightMoves():
            knightblock = KnightBlock(knightblock)
            location = knightblock.location
            location_tuple = location.totuple()
            if location< MAX and location > MIN and knightblock not in Original_ufos:
                if knightblock not in knightblocks:
                    knightblocks.append(knightblock)
    knights = set()
    while len(ufos) > 0:
        copy = ufos.copy()
        for ufo in copy:
            for knightblock in ufo.KnightMoves():
                knightblock = KnightBlock(knightblock)
                location = knightblock.location
                location_tuple = location.totuple()
                if location< MAX and location > MIN and location_tuple not in knights and knightblock not in Original_ufos:
                    knightblocks[knightblocks.index(knightblock)].helped(ufo)
        bestknight = max(list(range(len(knightblocks))),key=lambda x:knightblocks[x].helping)
        for ufo_remove in knightblocks[bestknight].help:
            if ufo_remove in ufos:
                ufos.remove(ufo_remove)
        knights.add(knightblocks[bestknight].location)

    print(len(knights))
    for knight in knights:
        print(knight)

'''
4
1 1
3 1
1 4
4 2
'''