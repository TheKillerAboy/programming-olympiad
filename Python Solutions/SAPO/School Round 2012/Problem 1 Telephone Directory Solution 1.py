vowels = list('aeiou')
if __name__ == '__main__':
    sentance = list(input('Input: '))
    out = sentance[0]
    for letter in sentance[1:]:
        if letter.lower() not in vowels:
            out+=letter
    print(out)

'''
21 Cavendish Avenue, eThekwini
'''