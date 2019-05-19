from fractions import Fraction

class Game:
    def __init__(self,coins,score,multipler):
        self.coins,self.score,self.multipler = coins,score,multipler
        self.real_score = self.score*self.multipler

    def next(self):
        for i in range(1,len(self.coins)-1):
            yield Game([*self.coins[:i],*self.coins[i+1:]],self.score+self.coins[i-1]*self.coins[i+1],self.multipler/((1-P**(len(self.coins)-1))*(len(self.coins)-1)))
        yield Game(self.coins[1:],self.score,self.multipler/((1-P**(len(self.coins)-1))*(len(self.coins)-1)))
        yield Game(self.coins[:-1], self.score,self.multipler / ((1 - P ** (len(self.coins) - 1)) * (len(self.coins) - 1)))

    def __repr__(self):
        return f'Score: {self.score} Multi: {self.multipler} Real: {self.real_score}'


if __name__ == '__main__':
    coins = (5,2,7)
    P = Fraction(3,8)
    games = [Game(coins,0,1/((1-P**len(coins))*len(coins)))]
    for _ in range(len(coins)-1):
        for game in (games.copy(),games.clear())[0]:
            games.extend(game.next())
    score = sum(map(lambda game:game.real_score,games))
    print(score)

'''
Prints all possible scores that can be achieved, but not the average
'''