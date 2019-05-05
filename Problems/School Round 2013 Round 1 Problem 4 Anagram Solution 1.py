from itertools import permutations

if __name__ == '__main__':
    word = list(input('Input: '))
    print(len(set(permutations(word,len(word))))-1)

'''
bookkeeper
'''