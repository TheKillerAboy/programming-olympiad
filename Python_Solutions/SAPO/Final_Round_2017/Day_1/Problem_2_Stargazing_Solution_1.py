class Coor:
    def __init__(self,loc):
        self.x,self.y = loc

    def __iter__(self):
        yield from (self.x,self.y)

    def distance(self,other):
        x,y = other
        return abs(x-self.x)+abs(y-self.y)

def get_inputs():
    return map(int,input('').split(' '))

def is_apart(constellation, STAR):
    for star in constellation:
        if STAR.distance(star) <= D:
            return True
    return False

def connected_constellations(STAR):
    out = []
    for i, constellation in enumerate(constellations):
        if is_apart(constellation,STAR):
            out.append(i)
    return out

if __name__ == '__main__':
    constellations = []
    N, D = get_inputs()
    stars = []
    for _ in range(N):
        stars.append(Coor(get_inputs()))
    for star in stars:
        apart_of = connected_constellations(star)
        if len(apart_of) == 0:
            constellations.append([star])
        else:
            new_constellations = []
            for c in apart_of:
                new_constellations.extend(constellations[c])
            new_constellations.append(star)
            constellations = [constellations[i] for i in range(len(constellations)) if i not in apart_of]
            constellations.append(new_constellations)
        print(len(constellations[-1]))