from itertools import permutations

class Coor:
    def __init__(self,loc):
        self.x, self.y = loc

    def __iter__(self):
        yield from (self.x,self.y)

    def distance(self,other):
        x,y = other
        return (self.x-x)**2+(self.y-y)**2

    @classmethod
    def all_positions(cls):
        for i in range(1,N+1):
            for j in range(1,M+1):
                yield Coor((i,j))

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __repr__(self):
        return ' '.join(map(str,self))

def get_score(arrangement):
    score = 0
    for old, new in zip(initial,arrangement):
        score += old.distance(new)
    return score

def get_farest(arrangement,loc):
    search = all_pos - set(arrangement)
    minial = loc.distance(max(search, key=lambda pos:loc.distance(pos)))
    for mi in sorted(search, key=lambda pos:loc.distance(pos),reverse=True):
        if loc.distance(mi) == minial:
            yield mi
        else:
            break

def get_max_for_prohority(prohority):
    maxs = [initial.copy()]
    for pos in range(K):
        for maxe in (maxs.copy(),maxs.clear())[0]:
            for farest in get_farest(maxe,maxe[prohority[pos]]):
                maxs.append(replace(maxe,prohority[pos],farest))
    return max(maxs,key=lambda maxe:get_score(maxe))

def replace(arrangement,pos,loc):
    out = arrangement.copy()
    out[pos] = loc
    return out

def get_input():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    N,M,K = get_input()
    initial = [Coor(get_input()) for _ in range(K)]
    all_pos = set(Coor.all_positions())
    print('\n'.join(map(str,max(map(get_max_for_prohority,permutations(list(range(K)),K)),key=lambda arrangement:get_score(arrangement)))))

'''
3 3 5
1 1
1 2
1 3
2 1
2 2
'''

'''
Much faster solution if K < N*M - K, uses a priority queue to check all combos fairest permutation
Much more complicated code, but it is much more efficient
'''