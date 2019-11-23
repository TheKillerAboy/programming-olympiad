import math

MOD = 10**9+7

def nCk(n,k):
    total = 1
    for i in range(n-k+1,n+1):
        total *= i
    for i in range(2,k+1):
        total //=i
    return total%MOD

class Coor:
    def __init__(self,loc):
        self.x,self.y = loc

    def __iter__(self):
        yield from (self.x,self.y)

    def __sub__(self, other):
        x,y = other
        return Coor((abs(self.x-x),abs(self.y-y)))

    def gradiant(self,other):
        x,y = other
        if self.x == x:
            return math.inf
        return (self.y-y)/(self.x-x)

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return hash(other) == hash(self)

    def __repr__(self):
        return f'x: {self.x} y: {self.y}'

def get_crits(locs):
    crits = set()
    for i,loc in enumerate(locs):
        gradiants = []
        for loc2 in list(locs)[i+1:]:
            gradiants.append((loc2,loc.gradiant(loc2)))
        current_crit = set()
        while len(gradiants) > 0:
            current = gradiants[0][1]
            if current in map(lambda grad:grad[1],gradiants[1:]):
                current_crit.add(frozenset({*{grad[0] for grad in gradiants if grad[1] == current},loc}))
                gradiants = [grad for grad in gradiants if grad[1] != current]
            else:
                del gradiants[0]
        crits.update(current_crit)
    return crits

def in_crits(crits,crit):
    for cri in crits:
        if crit.issubset(cri):
            return True
    return False

def get_inputs():
    return map(int,input('').split(' '))

def get_prob(locs,amount):
    out = nCk(len(locs),amount)
    crits = get_crits(locs)
    if len(crits) == 0:
        return out
    else:
        for crit in crits:
            length = len(crit)
            for size in range(3,min(length+1,amount)):
                out -= get_prob(set(locs)-set(crit),K-size)
        return out

if __name__ == '__main__':
    _locs = set()
    N,K = get_inputs()
    for _ in range(N):
        _locs.add(Coor(get_inputs()))
    print(get_prob(_locs,K))

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

'''
Solution 1 one is a constraint solution, it can only perform what is required of it. Meaning it can only take up to
5 Owls. Where this solution uses recursion to be able solve for any amount of Owls. It also uses a better method to
find petals that are directly between others with help from the inf math constant.
'''