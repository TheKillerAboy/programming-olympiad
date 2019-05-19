class Area:
    def __init__(self,width,height):
        self.width,self.height = width,height
        self.grid = []

    def add(self,row):
        self.grid.append(row)

    def __getitem__(self, item):
        x,y = tuple(item)
        return self.grid[x][y]

    def __setitem__(self, key, value):
        x,y = tuple(key)
        self.grid[x][y] = value

    def __contains__(self, item):
        x,y = tuple(item)
        return 0<=x<self.width and 0<=y<self.height

    def get_closest(self,start_loc):
        visited = {start_loc}
        paths = {Path(start_loc,0)}
        while len(paths)>0 and len(list(filter(lambda path:self[path.last]>0,paths)))==0:
            for path in (paths.copy(),paths.clear())[0]:
                for new_path in path.next(visited):
                    paths.add(new_path)
        if len(list(filter(lambda path:self[path.last]>0,paths)))==0:
            return None
        return list(filter(lambda path:self[path.last]>0,paths))[0].last


class Coor:
    def __init__(self,loc):
        self.x,self.y = tuple(loc)

    def __iter__(self):
        yield self.x
        yield self.y

    def __add__(self, other):
        x,y = tuple(other)
        return Coor((x+self.x,y+self.y))

    def __sub__(self, other):
        x,y = tuple(other)
        return Coor((x-self.x,y-self.y))

    def __len__(self):
        return abs(self.x)+abs(self.y)

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __hash__(self):
        return hash(tuple(self))

    def __str__(self):
        return f"x: {self.x},y: {self.y}"

class Path:
    def __init__(self,last,dis):
        self.last, self.dis = last,dis

    def next(self,visited):
        for offset in OFFSET:
            new_loc = self.last+offset
            if new_loc in area and new_loc not in visited:
                visited.add(new_loc)
                yield Path(new_loc,self.dis+1)



if __name__ == '__main__':
    OFFSET = []
    for i in range(-1,2):
        for j in range(-1,2):
            if(i,j) != (0,0):
                OFFSET.append(Coor((i,j)))
    N,M,Q = tuple(map(int,input('').split(' ')))
    area = Area(N,M)
    for _ in range(N):
        row = list(map(int,input('').split(' ')))
        print(row)
        area.add(row)
    queries = []
    for _ in range(Q):
        queries.append(tuple(map(int,input('').split(' '))))
    for type,a,b,K in queries:
        if type == 0:
            replace = {}
            need = K
            distance = 0
            while need > 0:
                best = area.get_closest(Coor((a,b)))
                if best == None:
                    for best,amount in replace.items():
                        area[best] = amount
                    distance = -1
                    break
                if area[best] >= need:
                    area[best] -= need
                    replace[best] = need
                    distance += need*(2*(len(best-(a,b))-1)+1)
                else:
                    need -= area[best]
                    replace[best] = area[best]
                    distance += area[best]*(2*(len(best-(a,b))-1)+1)
                    area[best] = 0
            print(distance)
        elif type == 1:
            area[(a,b)] = K
'''
4 5 6
0 0 1 0 2
1 0 0 0 0
0 0 0 1 0
4 0 0 0 1
0 0 0 2
0 2 0 6
0 3 4 3
0 3 3 12
1 0 0 1
0 0 0 2
'''