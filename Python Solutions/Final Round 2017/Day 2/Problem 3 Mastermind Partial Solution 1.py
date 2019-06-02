from random import randint, choices
from itertools import combinations

class Pair:
    def __init__(self,key,value):
        self.key,self.value = key,value

    def __hash__(self):
        return hash((self.key,self.value))

    def __eq__(self, other):
        return hash(self) == hash(other)

def get_inputs():
    return map(int,input('').split(' '))

def all_poss_group(A_group,B_group, A,B):
    for values in combinations(list(set(range(1,K+1)) - set(B_group)),N-A-B):
        h = 0
        j = 0
        out = []
        while j < N:
            if j in A_group.keys():
                out.append(A_group[j])
            elif j in B_group.keys():
                out.append(B_group[j])
            else:
                out.append(values[h])
                h+=1
            j+=1
        yield tuple(out)

def to_dict(tup):
    ag = tup
    tup = {}
    for key,value in ag:
        tup[key] = value
    return tup

def same(one,two):
    for i in two:
        if i in one:
            return True
    return False

def all_poss(current, A,B):
    for A_group in combinations([(i,current[i]) for i in range(N)],A):
        A_group = to_dict(A_group)
        for B_group in combinations(list(set(current)-set(A_group.values())),B):
            bg = B_group
            for indexs in combinations(list(range(N)),B):
                if not same(A_group.keys(),indexs):
                    B_group = {}
                    for key,value in zip(indexs,bg):
                        B_group[key] = value
                    yield from all_poss_group(A_group,B_group, A,B)

if __name__ == '__main__':
    N,K = get_inputs()
    all_pos = set()
    current = tuple(randint(1,K) for _ in range(N))
    while True:
        print(current)
        A,B = get_inputs()
        if len(all_pos) == 0:
            all_pos = list(set(all_poss(current,A,B)))
        else:
            all_pos.remove(current)
            new_allpos = set(all_poss(current,A,B))
            all_pos = [pos for pos in all_pos if pos in new_allpos]
        current = choices(all_pos)[0]

'''
Calculate all possible combinations for that input and remove all combos that wont work
Fastest determine method. Finding all combinations needs work on
'''