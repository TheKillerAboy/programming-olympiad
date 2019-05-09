class Grid:
    def __init__(self,size):
        self.w,self.h = size
        self.grid = []

    def append(self,row):
        self.grid.append(row)

    def __getitem__(self, item):
        x,y = item
        return self.grid[y][x]

    def get_rect(self,location,rect):
        value = 0
        x,y = location
        w,h = rect
        for i in range(w):
            for j in range(h):
                value+= self[x+i,y+j]
        return value

    def max_with_rect(self,rect):
        w,h = rect
        values = set()
        for i in range(self.w-w+1):
            for j in range(self.h-h+1):
                values.add(self.get_rect((i,j),rect))
        return max(values)

    def generate_all_rects(self):
        for i in range(1,self.w+1):
            for j in range(1,self.h+1):
                yield (i,j)

if __name__ == '__main__':
    grid = Grid((int(_) for _ in input('').split(' ')))
    for _ in range(grid.h):
        grid.append([int(_) for _ in input('').split(' ')])

    values = set()
    for rect in grid.generate_all_rects():
        values.add(grid.max_with_rect(rect))

    print(max(values))