class Cutter:
    def __init__(self,min,max):
        self.min, self.max = min,max

    def next(self):
        yield Cutter(self.min,(self.min+self.max)//2-1)
        yield Cutter((self.min+self.max)//2+1,self.max)

    def left(self):
        if self.max-self.min == 0:
            return 0
        else:
            return self.max-self.min+1

    def __repr__(self):
        return f'min: {self.min} max: {self.max}'

if __name__ == '__main__':
    N,M = map(int,input('').split(' '))
    cutters = [Cutter(1,N)]
    for _ in range(M):
        for cutter in (cutters.copy(),cutters.clear())[0]:
            cutters.extend(cutter.next())
    min_sum = N
    for prev,next in zip(cutters[:-1],cutters[1:]):
        min_sum = min(min_sum,prev.left()+next.left())
    print(M+min_sum)