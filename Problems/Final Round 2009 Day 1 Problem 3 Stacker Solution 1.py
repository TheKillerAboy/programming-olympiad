ALL = []
N,M = [int(_) for _ in input('').split(' ')]
for _ in range(N):
    ALL.append(int(input('')))


class Path:
    def __init__(self,path,value):
        self.path = path
        self.sum = sum(path)
        self.value = value

    def next(self,multi):
        for i in range(1,M+1):
            if self.sum+i <= N:
                SUM = 0
                if self.sum == 0:
                    SUM = sum(ALL[-i:])
                else:
                    SUM = sum(ALL[-i-self.sum:-self.sum])
                yield Path([*self.path,i],self.value+multi*SUM)
            else:
                yield self
                return

    def __repr__(self):
        return str(self.value)

    def __eq__(self, other):
        return self.path == other.path

    def __hash__(self):
        return hash(tuple(self.path))

if __name__ == '__main__':
    paths = {Path([],0)}
    muilti = 1
    _paths = set()
    while _paths != paths:
        _paths = paths.copy()
        paths.clear()
        for path in _paths:
            for new_path in path.next(muilti):
                paths.add(new_path)
        muilti*=-1
    paths = list(paths)
    best = min(paths,key=lambda x:abs(x.value))
    score = 0
    index = N
    for i in range(len(best.path)):
        if i%2 == 0:
            score += sum(ALL[index-best.path[i]:index])
        index -= best.path[i]
    print(score)

'''
10 3
5
2
0
1
4
3
5
2
0
0
'''
