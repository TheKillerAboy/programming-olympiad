class Tower:
    def __init__(self,height,value):
        self.height,self.value = height, value

    def __repr__(self):
        return f'{self.height} {self.value}'

    def __hash__(self):
        return hash((self.height,self.value))

    def __eq__(self, other):
        return hash(self) == hash(other)

class Towers:
    def __init__(self):
        self.towers = []

    def add(self,height,value):
        self.towers.append(Tower(height,value))
        self.max_index = self.towers.index(max(self.towers,key=lambda tower:tower.height))

    def next(self,index):
        height = self[index].height
        if index == 0:
            if self[1].height < height:
                yield 1
            if self[self.max_index+1].height < height:
                yield self.max_index+1
        else:
            if index > 0 and self[index - 1].height < height:
                yield index-1
            if index +1 < len(self.towers) and self[index + 1].height < height:
                yield index+1

    def __getitem__(self, item):
        if item <= self.max_index:
            return self.towers[self.max_index-item]
        else:
            return self.towers[item]

    def has_value(self,value):
        for i in range(len(self.towers)):
            if self.towers[i].value == value:
                yield Combo(i,value)

class Combo:
    def __init__(self,index,value):
        self.index, self.value = index, value

    def next(self):
        for next in towers.next(self.index):
            yield Combo(next,self.value+towers[next].value)

    def __repr__(self):
        return f'index: {self.index} value: {self.value}'

    def __hash__(self):
        return hash((self.index,self.value))

    def __eq__(self, other):
        return hash(self) == hash(other)

def get_inputs():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    towers = Towers()
    amount, queries = get_inputs()
    for height, value in zip(get_inputs(),get_inputs()):
        towers.add(height,value)
    queries = [get_inputs() for _ in range(queries)]
    for mode,v, W in queries:
        if mode == 0:
            diffrent = 0
            combos = {Combo(v,towers[v].value)}
            if towers[v].value == W:
                diffrent += 1
            while len(combos) > 0:
                for combo in (combos.copy(),combos.clear())[0]:
                    for next in combo.next():
                        combos.add(next)
                diffrent += len(list(filter(lambda combo:combo.value == W,combos)))
            print(diffrent)
        else:
            towers.towers[v].value = W

'''
4 5
-1 0 1 0
1 -1 1 0
0 0 1
1 3 7
1 1 1
0 1 2
0 0 8
'''