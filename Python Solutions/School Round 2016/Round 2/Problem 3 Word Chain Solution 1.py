from string import ascii_uppercase

def diffrences(w1,w2):
    for l in range(len(w1)):
        if w1[l] != w2[l]:
            yield l

def one_diffrent(w1,w2):
    return len(list(diffrences(w1,w2))) == 1

class WordChain:
    def __init__(self,w1,w2):
        self.w1,self.w2 = w1,w2

    def __hash__(self):
        index = list(diffrences(self.w1,self.w2))[0]
        if ascii_uppercase.index(self.w1[index])>ascii_uppercase.index(self.w2[index]):
            return hash((self.w2,self.w1))
        else:
            return hash((self.w1,self.w2))

    def __repr__(self):
        return self.w1 + ' '+self.w2

    def __eq__(self, other):
        return self.w1 == other or self.w2 == other

    def other(self,word):
        if self.w1 == word:
            return self.w2
        else:
            return self.w1

def alphabet(words):
    return sorted(words)[0]

if __name__ == '__main__':
    connects = set()
    words = input('Input: ').split(' ')
    counts = [0 for _ in range(len(words))]
    for w, w1 in enumerate(words):
        for w2 in words[w+1:]:
            if one_diffrent(w1,w2):
                connects.add(WordChain(w1,w2))
    for w, w1 in enumerate(words):
        for connection in connects:
            if w1 == connection:
                counts[w]+=1
    key_words = [word for w,word in enumerate(words) if counts[w] == min(counts)]
    chains = [[alphabet(key_words)]]
    while len(chains[0]) < len(words):
        chains_copy = chains.copy()
        chains.clear()
        for chain in chains_copy:
            word = chain[-1]
            w = words.index(word)
            for connection in connects:
                if word == connection and connection.other(word) not in chain:
                    chains.append([*chain,connection.other(word)])
    print(chains)
    print(' '.join(chains[0]))
'''
WALL TAIL TALL WALK BALL WAIL TALK
'''


'''
Solution Explanation:
    we first find all the links between all the words
    {
    for w, w1 in enumerate(words):
        for w2 in words[w+1:]:
            if one_diffrent(w1,w2):
                connects.add(WordChain(w1,w2))
    }
    by using the one_diffrent function to see if they are linkable
    
    then we find the amount of links a word has
    {
    for w, w1 in enumerate(words):
        for connection in connects:
            if w1 == connection:
                counts[w]+=1
    } 
    
    we then find the start of the change, this is the one with the fewest links
    this is because it is in the start of the chain
    {
    key_words = [word for w,word in enumerate(words) if counts[w] == min(counts)]
    }
    I use an for generator with checking if a word has the minimum score, as the start 
    of the chain and the end have the same amount of links
    
    The chain starts with the word that is in the begining of the alphabet
    {
    chains = [[alphabet(key_words)]]
    }
    
    I then processed to find every link possible with a stack method approciate
    I then assume the one at index 0 is the correct solution
'''