def max_height(n):
    if n <= half_n:
        return n
    else:
        return 2*half_n - n

class Coor:
    def __init__(self,loc):
        self.x,self.y = loc

    def next(self):
        yield Coor((self.x+1,self.y+1))
        yield Coor((self.x+1,self.y-1))

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __hash__(self):
        return hash((self.x,self.y))

MOD = 4993

if __name__ == '__main__':
    half_n = int(input(''))
    tracker = {Coor((0,0)):1}
    sub = 0
    for i in range(1,half_n*2):
        max_h = max_height(i)
        for loc, ways in (tracker.copy().items(),tracker.clear())[0]:
            for next_loc in loc.next():
                if 0<=next_loc.y<=max_h:
                    if next_loc in tracker:
                        tracker[next_loc] += ways
                    else:
                        tracker[next_loc] = ways
                    tracker[next_loc]%=MOD
        if i == half_n:
            sub = sum(tracker.values())%MOD
    k = next(iter(tracker.values()))-sub
    while k < 0:
        k += MOD
    print(k)

'''
A Valid solution to the problem, but a little slower
This is a object orientated solution taking inspiration from Solution 2, but in the way I regualary solve these problems
with an tree full method, iteratively. 
'''