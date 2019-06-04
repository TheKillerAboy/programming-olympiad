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

    def __repr__(self):
        return ' '.join(map(str,self))

def get_score(arrangement):
    score = 0
    for old, new in zip(initial,arrangement):
        score += old.distance(new)
    return score

def get_input():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    N,M,K = get_input()
    initial = [Coor(get_input()) for _ in range(K)]
    print('\n'.join(map(str,max(permutations(list(Coor.all_positions()),K),key=lambda arrangement:get_score(arrangement)))))
