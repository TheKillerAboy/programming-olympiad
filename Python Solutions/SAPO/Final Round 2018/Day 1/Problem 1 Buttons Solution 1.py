class Path:
    def __init__(self,dis,M):
        self.dis,self.M = dis,M

    def next(self):
        if self.M < N:
            yield Path(self.dis+1,self.M*A)
        yield Path(self.dis+1,self.M-1)

    def __eq__(self, other):
        return hash(self)==hash(other)

    def __hash__(self):
        return hash((self.M,))

if __name__ == '__main__':
    A,M,N = tuple(map(int,input('').split(' ')))
    paths = {Path(0,M)}
    while len(list(filter(lambda path:path.M==N,paths))) == 0:
        for path in (paths.copy(),paths.clear())[0]:
            for new in path.next():
                paths.add(new)
    print(list(filter(lambda path:path.M==N,paths))[0].dis)