class Chain:
    def __init__(self,chain):
        self.chain = chain

    def added(self,back):
        return Chain([*self.chain,back])

    def __len__(self):
        return len(self.chain)

    def __contains__(self, item):
        return item in self.chain

    def __repr__(self):
        return ' '.join(self.chain)

    def __hash__(self):
        return hash(tuple(self.chain))

    def __getitem__(self, item):
        return self.chain[item]

    @property
    def back(self):
        return self.chain[-1]

def diffrences(w1,w2):
    for l, letter in enumerate(w1):
        if letter != w2[l]:
            yield l

def one_diffrence(w1,w2):
    return len(list(diffrences(w1,w2))) == 1

def first_in_alphabet(words):
    return sorted(words)[0]

if __name__ == '__main__':
    words = input('Input: ').split(' ')
    chains = [Chain([word]) for word in words]
    while len(chains[0]) != len(words):
        chains_copy = chains.copy()
        chains.clear()
        for chain in chains_copy:
            for word in words:
                if word != chain.back and one_diffrence(word,chain.back) and word not in chain:
                    chains.append(chain.added(word))
    index = 0
    while len(chains)>1:
        index_words = [chain[index] for chain in chains]
        alpha_word = first_in_alphabet(index_words)
        chains = [chain for chain in chains if chain[index] == alpha_word]
        index+=1
    print(chains[0])

'''
This solution, although more primitive than the first one in terms of speed over very large chains
is most efficient in the time constraint the olympiads offer

It is very naive
I get a list of all possible chains, we know a chain could work if the length of the chain contains
every word
I use a set to somewhat increase time complexities
I then filter out all the chains that aren't in alphabetical order
!!! This last algorithm should be implemented in solution 1

The object is used only to make the main code more readable, because readable code
is code that can be more easily understood whilst programming
'''
