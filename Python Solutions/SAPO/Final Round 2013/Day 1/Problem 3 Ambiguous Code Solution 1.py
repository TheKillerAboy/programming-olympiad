def all_pairs(words):
    pairs = [[_] for _ in words[0]]
    for i in range(1,len(words)):
        pairs_copy = pairs.copy()
        pairs.clear()
        for sub_word in words[i]:
            for pair in pairs_copy:
                pairs.append((*pair,sub_word))
    return pairs

class Instruction:
    def __init__(self,args):
        self.start_word_index,self.start_index,self.end_word_index,self.end_index = args
        self.start_index-=1
        self.start_word_index-=1
        self.end_index-=1
        self.end_word_index-=1

def current_instructions(pair):
    for instruction in instructions:
        if pair[instruction.start_word_index][instruction.start_index] != pair[instruction.end_word_index][instruction.end_index]:
            return False
    return True

if __name__ == '__main__':
    num_words,num_instructions = tuple(map(int,input('').split(' ')))
    words = []
    for _ in range(num_words):
        inp = input('')
        first_space_index = inp.index(' ')
        amo_words, c_words = int(inp[:first_space_index]), inp[first_space_index+1:].split(' ')
        words.append(c_words)
    instructions = []
    for _ in range(num_instructions):
        instructions.append(Instruction(tuple(map(int,input('').split(' ')))))
    works = filter(current_instructions,all_pairs(words))
    works = list(works)[0]
    if len(works)==0:
        print('NO')
        exit()
    print('YES')
    for word in works:
        print(word)

'''
3 4
2 TREASURE TORTILLA
2 NORTH SOUTH
1 ISLAND
1 1 2 4
2 1 3 2
1 4 3 4
1 3 1 8
'''