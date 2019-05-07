class Player:
    def __init__(self,location):
        self.location = location

    def next(self):
        yield Player(self.location)
        if self.location+player_width<=court_size:
            yield Player(self.location+1)
        if self.location > 1:
            yield Player(self.location-1)

    def __contains__(self, item):
        return self.location<=item<self.location+player_width

    def __hash__(self):
        return hash((self.location,))

    def __eq__(self, other):
        return hash(other) == hash(self)

    def __repr__(self):
        return f'{self.location} - {self.location+player_width-1}'

if __name__ == '__main__':
    court_size, player_width, L = (int(_) for _ in input('').split(' '))
    dodgeballs = [int(_) for _ in input('').split(' ')]
    players = {Player(1)}
    for b, ball in enumerate(dodgeballs):
        players_copy = players.copy()
        players.clear()
        for player in players_copy:
            for next_player in player.next():
                if ball not in next_player:
                    players.add(next_player)
        if len(players) == 0:
            print(b+1)
            exit()
    print('Complete')

'''
40 5 36
40 30 20 10 1 2 3 4 6 5 7 9 17 10 16 11 1 40 14 13 16 11 18 9 20 7 15 23 19 26 5 8 15 30 12 33
'''