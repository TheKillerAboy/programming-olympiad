offsets = [(0,1),(0,-1),(1,0),(-1,0)]

def surrounded(loc):
    for offset in offsets:
        yield loc + offset

class Coor:
    def __init__(self,loc):
        self.x, self.y = loc

    def __iter__(self):
        yield from (self.x,self.y)

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __add__(self, other):
        x,y = other
        return Coor((self.x+x,self.y+y))

class Player:
    def __init__(self,location,life):
        self.location, self.life = location, life

class Mansion:
    width = 0
    height = 0
    def __init__(self,layout, player, switchs, visted):
        self.layout, self.player, self.switchs, self.visted = layout, player, switchs, visted
        if self[player.location] == '*':
            self.lit_cell(player.location)
            self.switchs += 1
        if self[player.location] == '_':
            self.player.life = 2

    def lit_cell(self,loc):
        for i in range(-1,2):
            for j in range(-1,2):
                new_loc = loc+(i,j)
                if new_loc in self and self[new_loc] != '*':
                    self[new_loc] = '_'

    def next(self):
        if self.player.life > 0:
            for new_loc in surrounded(self.player.location):
                if new_loc in self and new_loc not in self.visted:
                    yield Mansion(self.layout,Player(new_loc, self.player.life - 1),self.switchs,{*self.visted,new_loc})

    def __getitem__(self, item):
        x,y = item
        return self.layout[x][y]

    def __setitem__(self, key, value):
        x,y = key
        self.layout[x][y] = value

    def __contains__(self, item):
        y,x = item
        return 0<=x<self.width and 0<=y<self.height

    def __repr__(self):
        return str(self.player.life)

if __name__ == '__main__':
    Mansion.height, Mansion.width = map(int,input('').split(' '))
    layout = []
    for _ in range(Mansion.height):
        layout.append(list(input('')))
    for i in range(Mansion.height):
        for j in range(Mansion.width):
            if layout[i][j] == 'S':
                playerloc = Coor((i,j))
                layout[i][j] = '*'
    mansions = [Mansion(layout,Player(playerloc,2),0,{playerloc})]
    max_switchs = 0
    while True:
        for mansion in (mansions.copy(),mansions.clear())[0]:
            mansions.extend(mansion.next())
        if len(mansions) > 0:
            max_switchs = max(max_switchs,max(mansions,key=lambda mansion: mansion.switchs).switchs)
        else:
            break
    print(max_switchs)

'''
4 16
Sooooo****oo*ooo
*ooooo*oo*oo*ooo
*ooooo*oo*oo*ooo
****oo****oo****
'''

'''
Solution 2 is diffrent from Solution in the way that it has many mansions each with one player, and what places the 
player has visted instead of one mansion with multiple players each storing info from the mansion
This Solutions Datastructure is much more readable and makes it able to do much more complex work without lost
in performance
'''