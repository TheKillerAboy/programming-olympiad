from itertools import product

class State:
    breakable = []
    initialstate = []
    power = []
    def __init__(self,state):
        self.state = state
        self.diffrence = self.calc_diffrence()
        self.total_moves = sum(self.diffrence)
        self.actual = self.diffrence.copy()

    def calc_diffrence(self):
        out = []
        for initial, current in zip(self.initialstate,self.state):
            out.append(abs(current-initial))
        return out

    def calc_power(self):
        return sum(map(lambda power, state : power* state,self.power,self.state))

    def full_actual(self):
        index = 0
        length = len(self.state)
        while self.total_moves != Q and index < length:
            if self.breakable[index] - self.actual[index] >= 2:
                amount = ((self.breakable[index] - self.actual[index])//2)*2
                if amount <= self.total_moves - Q:
                    self.total_moves += amount
                    self.actual[index] += amount
                else:
                    self.total_moves = Q
                    self.actual[index] += Q - self.total_moves
            index += 1
        return self.total_moves == Q

    def __repr__(self):
        return ' + '.join(map(lambda power, state: f'{state}*{power}',self.power,self.state))

def get_inputs():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    N,Q = get_inputs()
    State.power = list(get_inputs())
    State.initialstate = list(get_inputs())
    State.breakable = list(get_inputs())

    for state in sorted(map(State,product([-1,0,1],repeat=len(State.initialstate))),key=lambda state:state.calc_power(), reverse=True):
        if state.total_moves%2 == Q%2:
            if state.full_actual():
                print(state.calc_power())
                exit()

'''
3 4
5 1 3
-1 0 1
2 2 2
'''