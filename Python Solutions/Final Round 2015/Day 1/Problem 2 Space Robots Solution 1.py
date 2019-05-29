class Coor:
    def __init__(self,loc):
        self.x,self.y,self.z = loc

    def __iter__(self):
        yield from (self.x,self.y,self.z)

    def __add__(self, other):
        x,y,z = other
        return Coor((self.x+x,self.y+y,self.z+z))

    def __eq__(self, other):
        return hash(tuple(self)) == hash(tuple(other))

class Intersection:
    order = ['up','north','east']
    def __init__(self, up, north, east):
        self.up,self.north,self.east =  up, north, east
        self.abbr = {'up': self.up, 'north': self.north, 'east': self.east}
        self.stop = 'up'
        self.counter = 0

    def count(self):
        self.counter-=1
        if self.counter <= 0:
            self.stop = self.order[(self.order.index(self.stop)+1)%3]
            self.counter = self.abbr[self.stop]

    def next(self,location):
        if self.stop != 'up':
            yield Location(location.loc+Coor((0,0,1)),location.time+1)
            yield Location(location.loc+Coor((0,0,-1)),location.time+1)
        if self.stop != 'north':
            yield Location(location.loc+Coor((0,1,0)),location.time+1)
            yield Location(location.loc+Coor((0,-1,0)),location.time+1)
        if self.stop != 'east':
            yield Location(location.loc+Coor((1,0,0)),location.time+1)
            yield Location(location.loc+Coor((-1,0,0)),location.time+1)

class Location:
    def __init__(self,loc,time):
        self.loc,self.time = loc, time

class Intersections:
    def __init__(self):
        self.intersections = {}
        self.locations = []

    def add(self,name,value):
        self.intersections[tuple(name)] = value

    def __contains__(self, item):
        return item in map(lambda loc:loc.loc,self.locations)

    def minimize_locations(self):
        copy = self.locations.copy()
        self.locations = []
        for location in self.intersections.keys():
            self.locations.append(min(filter(lambda loc:loc.loc == location,copy),key=lambda loc:loc.score))

    def __getitem__(self, item):
        return self.intersections[tuple(item)]

    def get_location(self,item):
        return list(filter(lambda loc:loc.loc == item,self.locations))[0]

‘’’
Add method to see what unique locations are in self.locations
‘’’

    def count(self):
        for key in self.intersections.keys():
            self.intersections[key].count()


if __name__ == '__main__':
    N,M,P,T = tuple(map(int,input('').split(' ')))
    intersections = Intersections()
    for i in range(N):
        for j in range(M):
            for k in range(P):
                intersections.add(Coor((i,j,k)),Intersection(*tuple(map(int,input('').split(' ')))))
    intersections.locations = [Location(Coor((0,0,0)),0)]
    while Coor((N-1,M-1,P-1)) not in intersections:
        for location in (intersections.locations.copy(),intersections.locations.clear())[0]:
            for new_location in intersections.intersections[location.loc].next(location):
                if new_location in intersections:
‘’’
Ise above described method instead
‘’’
                    intersections.locations.append(new_location)
        intersections.minimize_locations()
        intersections.count()
    print(intersections.get_location((N-1,M-1,P-1)).time*T)
