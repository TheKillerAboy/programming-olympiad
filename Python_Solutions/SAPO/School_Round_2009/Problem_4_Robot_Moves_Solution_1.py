class Coor:
    OFFSET_MOVES = (((i,j) for i in range(-1,2) if (i,j) != (0,0))for j in range(-1,2))
    MOVE_CODES = dict(u=(0,-1),d=(0,1),l=(-1,0),r=(1,0))
    def __init__(self,location):
        self.x,self.y = tuple(location)

    def __iter__(self):
        yield self.x
        yield self.y

    def __add__(self, other):
        x,y = tuple(other)
        return Coor((x+self.x,y+self.y))

    def offset_moves(self):
        for offset_move in self.OFFSET_MOVES:
            yield self+offset_move

    def move(self,move):
        return self+self.MOVE_CODES[move]

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return tuple(self) == tuple(other)

    def __repr__(self):
        return f'x: {self.x} y: {self.y}'

class Boundaries:
    def __init__(self,location,include0 = True):
        self.w,self.h = tuple(location)
        self.include0 = include0

    def __contains__(self, item):
        x,y = tuple(item)
        if self.include0:
            return 0<=x<self.w and 0<=y<self.h
        else:
            return 0<x<=self.w and 0<y<=self.h

    def __iter__(self):
        for i in range(self.w):
            for j in range(self.h):
                yield (i,j)

if __name__ == '__main__':
    w = int(input('Enter the width M: '))
    h = int(input('Enter the height N: '))
    boundry = Boundaries((w,h))
    moves = input('Enter the initial instructions: ')
    locations = {Coor((x,y)) for x,y in boundry}
    for move in moves:
        locations_copy = locations.copy()
        locations.clear()
        for location in locations_copy:
            location_o = location.move(move)
            if location_o in boundry:
                locations.add(location_o)
            else:
                locations.add(location)
    locationss = {frozenset(locations)}
    counter = 0
    minlocs = len(list(locationss)[0])
    while minlocs > 1:
        print(minlocs)
        counter+=1
        locationss_copy = locationss.copy()
        locationss.clear()
        for locations in locationss_copy:
            locations_copy_copy = locations.copy()
            locations = set()
            for move in 'lrud':
                locations_copy = set(locations_copy_copy.copy())
                locations.clear()
                for location in locations_copy:
                    location_o = location.move(move)
                    if location_o in boundry:
                        locations.add(location_o)
                    else:
                        locations.add(location)
                locationss.add(frozenset(locations))
        minlocs = len(min(locationss,key=lambda locations:len(locations)))
        locationss = {locations for locations in locationss if len(locations) == minlocs}
    print(f'You need to issue a further {counter} instructions.')

'''
Enter the width M: 100
Enter the height N: 100
Enter the initial instructions: lrudrudludlrdlru
'''