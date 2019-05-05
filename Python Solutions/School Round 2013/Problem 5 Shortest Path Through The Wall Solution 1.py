class Path:
    def __init__(self,dist,index):
        self.dist = dist
        self.index = index

    @classmethod
    def distance(cls,a,b):
        return abs(a-b)

    def __hash__(self):
        return hash((self.dist,self.index))

    def next(self,a):
        return Path(Path.distance(self.index,a)+self.dist+1,a)

    def __repr__(self):
        return f'distance: {self.dist} index: {self.index}'

if __name__ == '__main__':
    paths = set()
    N = int(input(''))
    blocks = []
    for _ in range(N):
        blocks.append(tuple([int(x) for x in input('').split(' ')]))
    paths.add(Path(1,blocks[0][0]))
    paths.add(Path(1,blocks[0][1]))
    for i in range(1,N):
        paths_copy = paths.copy()
        paths.clear()
        for sub in blocks[i]:
            for path in paths_copy:
                paths.add(path.next(sub))
    print(min(paths,key=lambda path:path.dist).dist)

'''
10
2 42
67 12
50 51
98 5
14 92
11 17
28 79
13 37
100 1
86 83
'''