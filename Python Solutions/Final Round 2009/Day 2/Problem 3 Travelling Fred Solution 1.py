class FlightPlan:
    def __init__(self,path):
        self.path = path
        self.last = path[-1]
        self.length = len(self.path)

    def next(self):
        for to in airports.flights_from(self.last):
            if not self.isPattern(to):
                yield FlightPlan([*self.path,to])

    def isPattern(self,to):
        for i in range(2,self.length//2):
            if self.isIn(self.path[:self.length-i+1],[*self.path[self.length-i+1:],to]):
                return True
        return False

    def __bool__(self):
        if set(range(T)).issubset(self.path) and self.last == 0:
            return True
        return False

    @classmethod
    def isIn(cls,bigger,smaller):
        lenbig = len(bigger)
        lensma = len(smaller)
        for i in range(lenbig-lensma):
            if bigger[i:i+lensma] == smaller:
                return True
        return False

class Airports:
    def __init__(self):
        self.airports = {i:set() for i in range(C)}

    def add(self, airport, to):
        self.airports[airport].add(to)

    def flights_from(self,airport):
        yield from self.airports[airport]

    def __getitem__(self, item):
        return self.airports[item]

    def __setitem__(self, key, value):
        self.airports[key] = value

def get_input():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    C,T,F = get_input()
    airports = Airports()
    for _ in range(F):
        airports.add(*get_input())
    flightplans = [FlightPlan([0])]
    while not any(flightplans):
        for flightplan in (flightplans.copy(),flightplans.clear())[0]:
            flightplans.extend(flightplan.next())
    print(next(filter(bool,flightplans)).length-1)

'''
7 4 12
0 5
0 4
1 0
1 2
2 6
3 0
3 6
4 3
4 5
6 1
6 2
6 5
'''