def get_inputs():
    return map(int,input('').split(' '))

class Translator:
    def __init__(self):
        self.langs = []

    def add(self,lang):
        self.langs.append(lang)

    def knows(self,lang):
        return lang in self.langs

class Chain:
    def __init__(self,chain,added,lasttranslator):
        self.chain = chain
        self.last = chain[-1]
        self.added = added
        self.lasttranslator = lasttranslator

    def next(self):
        for i, translator in enumerate(translators):
            if translator.knows(self.last):
                for lang in translator.langs:
                    if lang not in self.chain:
                        yield Chain([*self.chain,lang],self.added,i)

    def __repr__(self):
        return ' '.join(map(str,self.chain))

def better(first,second):
    if len(first) < len(second):
        return True
    elif len(first) == len(second):
        if set([list(f)[0] for f in first])<set([list(f)[0] for f in second]):
            return True
    return False

if __name__ == '__main__':
    N,L = get_inputs()
    P = int(input(''))
    translators = [Translator() for _ in range(N)]
    for _ in range(P):
        t,l = get_inputs()
        translators[t-1].add(l)

    chains = []
    for i, translator in enumerate(translators):
        if translator.knows(1):
            chains.append(Chain([1],set(),i))
    while len(chains[0].chain) != L:
        for chain in (chains.copy(),chains.clear())[0]:
            next = list(chain.next())
            if len(next) == 0:
                for l in range(1,L+1):
                    if l not in chain.chain and l not in translators[chain.lasttranslator].langs:
                        next.append(Chain([*chain.chain,l],{*chain.added,frozenset([chain.lasttranslator,l])},chain.lasttranslator))
            chains.extend(next)
    cursor = chains[0].added
    for chain in chains[1:]:
        if not better(cursor,chain.added):
            cursor = chain.added
    for change in map(list,cursor):
        print(' '.join(map(str,change)))

'''
4 7
8
4 7
1 1
1 2
2 3
2 2
3 4
3 5
3 6
'''