from fractions import Fraction

class Game:
    def __init__(self,locations, score):
        self.locations, self.score = locations, score

    def next(self):
        yield Game(self.locations[1:],self.score)
        for i in range(1,len(self.locations)-1):
            yield Game([*self.locations[:i],*self.locations[i+1:]],self.score+self.locations[i-1]*self.locations[i+1])
        yield Game(self.locations[:len(self.locations)-1],self.score)

    def __repr__(self):
        return ' '.join(map(str,self.locations))


def get_scores(size):
    record = P
    yield record
    for i in range(size):
        record *= (1-P)
        yield record

def get_score(game):
    next_games = list(game.next())
    if len(next_games) > 2:
        score = Fraction(0)
        for n_game, mul in zip(next_games, get_scores(len(next_games))):
            score += get_score(n_game) * mul / (1 - P**len(next_games))
        return score
    else:
        return game.score

def get_output(score):
    for i in range(M):
        if (i*score.denominator-score.numerator)%M == 0:
            return i

if __name__ == '__main__':
    N,s,t,M = tuple(map(int,input('').split(' ')))
    game = []
    for _ in range(N):
        game.append(int(input('')))
    game = Game(game,Fraction(0))
    P = Fraction(s,t)
    score = get_score(game)
    print(get_output(score))

'''
5 3 8 9887
5
6
3
2
8
'''

'''
Example 2 of doesnt yield the same result
'''