from math import log2


class Victory:
    def __init__(self,win,lose):
        self.win,self.lose = win,lose

    def __hash__(self):
        return hash((self.win,self.lose))

    def __eq__(self, other):
        return hash(self) == hash(other)

def get_children(_player):
    for victory in victories:
        if victory.win == _player:
            yield victory.lose

def best(_player):
    players = {victor}
    length = 1
    while _player not in players:
        players_copy = players.copy()
        players.clear()
        for player in players_copy:
            for loser in get_children(player):
                players.add(loser)
        length+=1
    return length

def worst(_player):
    all_players = {victor}
    players = {victor}
    while len(players)>0:
        players_copy = players.copy()
        players.clear()
        for player in players_copy:
            for loser in get_children(player):
                if loser not in get_children(_player):
                    players.add(loser)
                    all_players.add(loser)
    return len(all_players)

def round_size(N,round):
    return 2**(N-round-1)

def generate_victories():
    contestants = int(input(''))
    second = list(map(int,input('').split(' ')))
    N = int(log2(contestants))
    victories = set()
    for i in range(N):
        first = second
        second = list(map(int,input('').split(' ')))
        size = round_size(N,i)
        for j in range(size):
            both = first[2*j:2*j+2]
            winner = second[j]
            loser = [loser for loser in both if loser != winner][0]
            victories.add(Victory(winner,loser))
    return victories, second[0]


if __name__ == '__main__':
    victories, victor = generate_victories()
    for i in range(1,8+1):
        print(f'{best(i)} {worst(i)}')

'''
8
1 2 3 4 5 6 7 8
1 4 5 8
1 8
1
'''