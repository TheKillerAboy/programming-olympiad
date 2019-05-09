from string import ascii_uppercase

def get_further_down_alphabet(letter,n):
    return ascii_uppercase[(ascii_uppercase.index(letter)+n)%len(ascii_uppercase)]

if __name__ == '__main__':
    word = input('Word? ')
    N = int(input('N? '))
    word = word[-N:] + word[:-N]
    word = list(word)
    for l, letter in enumerate(word):
        word[l] = get_further_down_alphabet(letter,N)
    print(''.join(word))

'''
Word? EMDVENZKCFUTJXUGKYSARH
N? 10
'''