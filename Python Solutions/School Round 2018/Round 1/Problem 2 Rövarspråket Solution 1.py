from string import ascii_lowercase

if __name__ == '__main__':
    consonants = list(ascii_lowercase)
    for letter in list('aeiou'):
        consonants.remove(letter)
    out = ''
    word = input('Input: ')
    for letter in word:
        if letter in consonants:
            out += letter+'o'+letter
        else:
            out+=letter
    print(out)

'''
what a tangled web we weave
'''