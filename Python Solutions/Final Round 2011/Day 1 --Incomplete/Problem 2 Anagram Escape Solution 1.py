def isAnagram(seq1,seq2):
    return sorted(seq1)==sorted(seq2)

def n_out(iter,n):
    for i in range(len(iter)-n):
        yield tuple(iter[i:i+n])

if __name__ == '__main__':
    N,K = (int(_) for _ in input('').split(' '))
    anagram = [int(_) for _ in input('').split(' ')]
    letter = [int(_) for _ in input('').split(' ')]
    days = 0
    for pos_anagram in n_out(letter,len(anagram)):
        if isAnagram(anagram,pos_anagram):
            days+=1
    print(days)

'''
3 7
93 37 93
56 93 93 37 93 42 37
'''