from itertools import combinations

class Coor:
    def __init__(self, location):
        self.x, self.y = location

    def __iter__(self):
        yield self.x
        yield self.y

    def __sub__(self, other):
        x, y = tuple(other)
        return Coor((self.x-x,self.y-y))

    def length_easy(self):
        return self.x**2+self.y**2

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return tuple(self) == tuple(other)

    def __repr__(self):
        return f'x: {self.x} y: {self.y}'

def isAlign(points):
    x_points = {point.x for point in points}
    y_points = {point.y for point in points}
    if len(x_points)==2 and len(y_points)==2:
        return True
    return False

if __name__ == '__main__':
    amount = int(input(''))
    points = []
    for _ in range(amount):
        points.append(Coor((int(_) for _ in input('').split(' '))))
    squares = 0
    for pos_square in combinations(points,4):
        if isAlign(pos_square):
            squares+=1
    print(squares)
