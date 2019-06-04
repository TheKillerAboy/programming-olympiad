class Rooms:
    def __init__(self):
        self.rooms = {}

    def add(self,fro,to):
        self.__add(fro,to)
        self.__add(to,fro)

    def __add(self,fro,to):
        if fro in self.rooms:
            self.rooms[fro].add(to)
        else:
            self.rooms[fro] = {to}

    def next(self,fro):
        yield from self.rooms[fro]

class Path:
    def __init__(self,path):
        self.path = path
        self.last = path[-1]

    def __bool__(self):
        return self.last == last and len(set(self.path[:-1])) == len(self.path) - 1

    def next(self):
        for next in rooms.next(self.last):
            if next == last or next not in self.path:
                yield Path([*self.path,next])

    def __repr__(self):
        return '\n'.join(map(str,[len(self.path),*self.path]))


def get_input():
    return int(input(''))

if __name__ == '__main__':
    rooms = Rooms()
    N = get_input()
    rooms_ = [get_input() for _ in range(N)]
    last = rooms_[-1]
    for fro, to in zip(rooms_[:-1],rooms_[1:]):
        rooms.add(fro,to)
    paths = [Path([1])]
    while not any(paths):
        for path in (paths.copy(),paths.clear())[0]:
            paths.extend(path.next())
    print(next(filter(bool,paths)))

'''
6
1
2
3
4
1
3
'''