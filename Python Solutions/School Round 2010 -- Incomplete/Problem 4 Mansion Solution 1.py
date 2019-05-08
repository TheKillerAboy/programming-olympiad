class Coor:
    OFFSET_MOVES = []
    for i in range(-1,2):
        for j in range(-1,2):
            if (i,j) != (0,0):
                OFFSET_MOVES.append((i,j))

    PERFECT_MOVES = [(-1,0),(1,0),(0,-1),(0,1)]

    def __init__(self,location):
        self.x , self.y = tuple(location)

    def __iter__(self):
        yield self.x
        yield self.y

    def __add__(self, other):
        x,y = tuple(other)
        return Coor((self.x+x,self.y+y))

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return tuple(self)==tuple(other)

    def next_moves(self):
        for offset_move in self.OFFSET_MOVES:
            yield self+offset_move

    def next_perfect_moves(self):
        for offset_move in self.PERFECT_MOVES:
            yield self+offset_move

    def __repr__(self):
        return f'x: {self.x} y: {self.y}'

class Path:
    def __init__(self,path,life,lights,mansion):
        self.path,self.life,self.lights = path,life,lights
        self.last = path[-1]
        self.mansion = mansion.copy()

    def next(self):
        if self.life > 0:
            for new_move in self.last.next_perfect_moves():
                if new_move in mansion and new_move not in self.path:
                    yield Path([*self.path,new_move],self.life-1,self.lights,self.mansion.copy())

    def __hash__(self):
        return hash(tuple(self.path))

    def __eq__(self, other):
        return hash(self) == hash(other)

class Mansion:
    def __init__(self,location):
        self.w,self.h = tuple(location)
        self.cells = []

    def __contains__(self, item):
        x,y = tuple(item)
        return 0<=x<self.w and 0<=y<self.h

    def __getitem__(self, item):
        x,y = tuple(item)
        return self.cells[y][x]

    def __setitem__(self, key, value):
        x,y = tuple(key)
        self.cells[y][x] = value

    def append(self,row):
        self.cells.append(row)
        if 'S' in row:
            self.start = Coor((row.index('S'),len(self.cells)-1))

    def trigger_switch(self,location):
        location = Coor(location)
        self[location] = '$'

    def copy(self):
        out = Mansion((self.w,self.h))
        out.cells = self.cells.copy()
        out.start = self.start
        return out


if __name__ == '__main__':
    mansion = Mansion((7,3))
    cells = '''*oo*ooo
ooooooo
Sooooo*'''
    for row in cells.split('\n'):
        mansion.append(list(row))
    paths = {Path([mansion.start],2,0,mansion)}
    mansion.trigger_switch(mansion.start)
    max_lights = 0
    while len(paths) > 0:
        max_lights = max(paths,key = lambda path:path.lights).lights
        paths_copy = paths.copy()
        paths.clear()
        for path in paths_copy:
            for next_path in path.next():
                if next_path not in paths:
                    current = next_path.last
                    if next_path.mansion[current] == '*':
                        next_path.mansion.trigger_switch(current)
                        next_path.lights += 1
                    if next_path. mansion[current] == '$':
                        next_path.life = 3
                    paths.add(next_path)
    print(f'I can switch on {max_lights} lights')