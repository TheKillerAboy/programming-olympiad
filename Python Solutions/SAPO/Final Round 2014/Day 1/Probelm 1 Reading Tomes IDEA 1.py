class Chain:
    def __init__(self,combo):
        self.combo = combo

    def next(self,series):
        for word in series:
            yield Chain(self.combo+word)

def brack_split(word):
    word = word.replace('{',' ',1)
    word = ' '.join(word.rsplit('}', 1))
    if word[0] == ' ':
        word = word[1:]
    if word[-1] == ' ':
        word = word[:-1]
    word = word.replace('}{',' ')
    return word.split(' ')

def all_combonations(combo):
    out = {Chain('')}
    for subcombo in combo:
        for subsubcombo in (out.copy(),out.clear())[0]:
            if subcombo in types.keys():
                out.update(subsubcombo.next(types[subcombo]))
            else:
                out.update(subsubcombo.next([subcombo]))
    return out


if __name__ == '__main__':
    N,M,L = tuple(map(int,input('').split(' ')))
    types = {}
    for _ in range(N):
        word, amount, *words = tuple(input('').split(' '))
        types[word] = words
    combonations = []
    for _ in range(M):
        combonations.append(brack_split(input('')))
    word = ''
    for _ in range(L):
        word+=input('')

    occure = []

    for combo in combonations:
        total = 0
        for subcombo in all_combonations(combo):
            if subcombo in combo:
                total += 1
        occure.append(total)

    print('\n'.join(map(str,occure)))