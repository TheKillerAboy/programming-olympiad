from itertools import permutations

class Stand:
    def __init__(self,height,price):
        self.height, self.price = height, price

def zero_func(value):
    if value > 0:
        return value
    return 0

def calc_score(order):
    stand = order[0]
    score = stand.height*stand.price
    max_height = stand.height
    for stand in order[1:]:
        score += stand.price * zero_func(stand.height - max_height)
        max_height = max(max_height,stand.height)
    return score

if __name__ == '__main__':
    N = int(input(''))
    stands = []
    for _ in range(N):
        stands.append(Stand(*tuple(map(int,input('').split(' ')))))
    max_score = 0
    for order in permutations(stands):
        max_score = max(max_score,calc_score(order))
    print(max_score)