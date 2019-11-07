from string import ascii_lowercase as alphabet

if __name__ == '__main__':
    word = list(input('Input: '))
    for before, current in zip(word[:-1],word[1:]):
        if alphabet.index(before)>alphabet.index(current):
            print('False')
            exit()
    print('True')