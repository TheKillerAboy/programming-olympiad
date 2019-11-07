offsets = [(-1,0),(1,0),(0,1),(0,-1)]

class Player:
    def __init__(self,visited,sticks):
        self.visited, self.sticks = visited,sticks
        self.last = self.visited[-1]

    def next(self):
        for next_loc in map(lambda offset:self.last+offset,offsets):
            if next_loc not in self.visited and next_loc in cave:
                if cave[next_loc] == '#':
                    if self.sticks > 0:
                        yield Player([*self.visited,next_loc],self.sticks - 1)
                else:
                    yield Player([*self.visited,next_loc],self.sticks)

    def __repr__(self):
        return f'x: {self.last.x} y: {self.last.y} l: {self.sticks}'

class Coor:
    def __init__(self,loc):
        self.x,self.y = loc

    def __iter__(self):
        yield from (self.x,self.y)

    def __add__(self, other):
        x,y = other
        return Coor((x+self.x,self.y+y))

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return hash(self) == hash(other)

class Cave:
    def __init__(self):
        self.cave = []
        self.width = 0
        self.height = 0

    def __getitem__(self, item):
        y,x = item
        return self.cave[x][y]

    def __setitem__(self, key, value):
        y,x = key
        self.cave[x][y] = value

    def __contains__(self, item):
        x,y = item
        return 0<=x<self.width and 0<=y<self.height

if __name__ == '__main__':
    cave = Cave()
    cave.height,cave.width,sticks = map(int,input('').split(' '))
    for _ in range(cave.height):
        cave.cave.append(list(input('')))
    for j in range(cave.height):
        for i in range(cave.width):
            if cave.cave[j][i] == 'S':
                start = Coor((i,j))
            elif cave.cave[j][i] == 'E':
                end = Coor((i,j))
    players = {Player([start],sticks)}
    distance = 0
    while end not in map(lambda player:player.last,players):
        for player in (players.copy(),players.clear())[0]:
            players.update(player.next())
        distance+=1
    print(distance)

'''
6 8 2
.S......
########
.###....
.#.#####
.#...###
...#..#E
'''