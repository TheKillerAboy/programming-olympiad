from itertools import combinations

def nCk(n,k):
    total = 1
    for i in range(n-k+1,n+1):
        total *=  i
    for i in range(2,k+1):
        total //=i
    return total

class Coor:
    def __init__(self,loc):
        self.x,self.y = loc

    def __iter__(self):
        yield from (self.x,self.y)

    def __sub__(self, other):
        x,y = other
        return Coor((abs(self.x-x),abs(self.y-y)))

    def gradiant(self,other, type = None):
        x,y = other
        return (self.y-y)/(self.x-x)

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return hash(other) == hash(self)

    @classmethod
    def inline(cls,locs):
        first,second = locs[0:2]
        if first.x == second.x:
            for loc in locs[2:]:
                if first.x != loc.x:
                    return False
            return True
        elif first.y == second.y:
            for loc in locs[2:]:
                if first.y != loc.y:
                    return False
            return True
        else:
            gra = first.gradiant(second)
            for loc in locs[2:]:
                try:
                    if first.gradiant(loc) != gra:
                        return False
                except:
                    return False
            return True

def get_crits(locs,size):
    crits = []
    for loc_combo in combinations(locs,size):
        if Coor.inline(loc_combo):
            crits.append(loc_combo)
    return crits

def in_crits(crits,crit):
    for cri in crits:
        if crit.issubset(cri):
            return True
    return False

def get_inputs():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    locs = set()
    N,K = get_inputs()
    for _ in range(N):
        locs.add(Coor(get_inputs()))
    out = nCk(N,K)
    crits = []
    for size in range(K,2,-1):
        for critcombo in map(set,get_crits(locs,size)):
            if not in_crits(crits,critcombo):
                crits.append(critcombo)
    for crit in crits:
        length = len(crit)
        for size in range(3,length+1):
            out -= nCk(N-length,K-size)
    print(out)

'''
7 4
0 0
0 5
0 9
5 5
10 5
5 7
10 14
'''