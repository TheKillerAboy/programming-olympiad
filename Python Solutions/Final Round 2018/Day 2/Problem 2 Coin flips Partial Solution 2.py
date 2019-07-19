from fractions import Fraction

def k_prob(n):
    n = n+1
    return P*((1-P)**(n-1))

def score_removing(n,game):
    if n == 0 or n == len(game) - 1:
        return 0
    return game[n-1]*game[n+1]

def get_score(game):
    score = 0
    if len(game) == 2:
        return 0
    multipler = 1/(1-k_prob(len(game))/P)
    for c in range(1,len(game)-1):
        print(score_removing(c,game))
        score += k_prob(c)*(get_score([*game[:c],*game[c+1:]])+score_removing(c,game))
    score*=multipler
    print('Multiplier',len(game),multipler,game,'Score',score)
    return score

def get_output(score):
    try:
        x,y = map(int,str(score).split('/'))
    except:
        x = int(score)
        y = 1
    for k in range(M):
        if k*y % M == 1:
            break
    return x*k % M

if __name__ == '__main__':
    N,s,t,M = tuple(map(int,input('').split(' ')))
    P = Fraction(s,t)
    game = []
    for _ in range(N):
        game.append(int(input('')))
    for n in range(N):
        print(n,k_prob(n))
    print(get_output(get_score(game)))