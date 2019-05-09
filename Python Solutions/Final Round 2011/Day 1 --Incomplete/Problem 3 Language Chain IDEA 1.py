class Translator:
    def __init__(self):
        self.languages = set()

    def add(self,value):
        self.languages.add(value)

    def knows(self,language):
        return language in self.languages

class Chain:
    def __init__(self,chain):
        self.chain = chain

    def __hash__(self):
        return hash(tuple(sorted(self.chain)))

    def __eq__(self, other):
        chains = [self,other]
        min_chain = min(chains,key=lambda chain:len(chain))
        max_chain = max(chains,key=lambda chain:len(chain))
        return set(min_chain.chain).issubset(max_chain.chain)

    def __len__(self):
        return len(self.chain)

    @property
    def last(self):
        return self.chain[-1]

    def next(self,translator):
        if translator.knows(self.last):
            for lang in translator.languages:
                if lang not in self.chain:
                    yield Chain([*self.chain,lang])

    def __repr__(self):
        return self.chain.__repr__()

def get_input():
    return (int(_) for _ in input('').split(' '))

def get_info(P):
    for _ in range(P):
        yield get_input()

def languages():
    yield from range(1,L+1)

if __name__ == '__main__':
    N,L = get_input()
    P = int(input(''))
    translators = [Translator() for _ in range(N)]
    for index, language in get_info(P):
        translators[index-1].add(language)
    chains = {Chain([lang]) for lang in range(1,L+1)}
    all_chains = set()
    while len(chains) > 0:
        all_chains.update(chains)
        chains_copy = chains.copy()
        chains.clear()
        for chain in chains_copy:
            for trans in translators:
                for new_chain in chain.next(trans):
                    chains.add(new_chain)
    all_chains=list(all_chains)
    all_chains.sort(key=lambda chain:len(chain),reverse=True)
    new_all_chains = []
    for chain in all_chains:
        pr
        inlst = False
        for chain_ in new_all_chains:
            if chain_ == chain:
                inlst = True
                break
        if not inlst:
            new_all_chains.append(chain)
    print(new_all_chains)

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