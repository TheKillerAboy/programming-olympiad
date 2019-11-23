from random import randint, random
from fractions import Fraction

class Pair:
    def __init__(self,key,value):
        self.key,self.value = key,value

    def __hash__(self):
        return hash((self.key,self.value))

    def __eq__(self, other):
        return hash(self) == hash(other)

def get_inputs():
    return map(int,input('').split(' '))

def set_P(key,value):
    if type(key) in (tuple,Pair):
            P_pair[key] = P_pair[key] + value*(1/(99-iterations))
    else:
            P_val[key] = P_val[key] + value*(1/(99-iterations))

def get_best_at(pos):
    MAX = Pair(0,0)
    for i in range(1,K+1):
        if P_val[i]*P_pair[(pos,i)] > MAX.value:
            if random() > 1/(1+iterations):
                MAX.key = i
                MAX.value = P_val[i]*P_pair[(pos,i)]
    return MAX.key

def get_best():
    out = []
    for i in range(0,N):
        out.append(get_best_at(i))
    return out

if __name__ == '__main__':
    iterations = 0
    P_val = {}
    P_pair = {}
    N,K = get_inputs()
    current = [randint(1,K) for _ in range(N)]
    for i in range(1,K+1):
        P_val[i] = random()
        for j in range(N):
            P_pair[Pair(j,i)] = random()
    while True:
        print(current)
        A,B = get_inputs()
        for i,value in enumerate(current):
            set_P((i,value),Fraction(A,N))
            set_P(value,Fraction(A+B,N))
        current = get_best()
        iterations+=1
