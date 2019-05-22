from time import time

moves = ((1, 2),(-1, 2),(1, -2),(-1, -2),(2, 1),(2, -1),(-2, 1),(-2, -1),)

class Knight:
    def __init__(self,dist,location):
        self.location = location
        self.dist = dist

    def next(self):
        for offset in moves:
            next_knight= Knight(self.dist+1,self.location + offset)
            if next_knight.location in board:
                if next_knight not in all_knights:
                    yield next_knight

    def __hash__(self):
        return hash(self.location)

    def __eq__(self, other):
        return hash(other) == hash(self)

    def __repr__(self):
        return str(self.dist)

class Coor:
    def __init__(self,location):
        self.x,self.y = Coor.tuple(location)

    def __add__(self, other):
        x,y = Coor.tuple(other)
        return Coor((self.x+x,self.y+y))

    def __hash__(self):
        return hash((self.x,self.y))

    @classmethod
    def tuple(cls,other):
        if type(other) == Coor:
            return other.x , other. y
        elif type(other) == list:
            return tuple(other[:2])
        else:
            return other

class Board:
    def __init__(self,location):
        self.w,self.h = Coor.tuple(location)

    def __contains__(self, item):
        x,y = Coor.tuple(item)
        return 0<x<=self.w and 0<y<=self.h

if __name__ == '__main__':
    board = Board([int(_) for _ in input('').split(' ')])
    start = Knight(0,Coor([int(_) for _ in input('').split(' ')]))
    end = Knight(0,Coor([int(_) for _ in input('').split(' ')]))
    all_knights = {start}
    current_knights = all_knights.copy()
    while end not in all_knights:
        current_knights_copy = current_knights.copy()
        current_knights.clear()
        for knight in current_knights_copy:
            for next_knight in knight.next():
                current_knights.add(next_knight)
                all_knights.add(next_knight)
    all_knights = list(all_knights)
    print(all_knights[all_knights.index(end)])

'''
100 100
15 2
100 100
'''