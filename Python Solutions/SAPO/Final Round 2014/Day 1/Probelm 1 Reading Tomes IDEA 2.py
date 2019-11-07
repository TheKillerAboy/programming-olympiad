def brack_split(word):
    word = word.replace('{',' ',1)
    word = ' '.join(word.rsplit('}', 1))
    if word[0] == ' ':
        word = word[1:]
    if word[-1] == ' ':
        word = word[:-1]
    word = word.replace('}{',' ')
    return word.split(' ')

def all_combonations(combo):
    out = set()
    subcombonations = set()
    subcombo = combo[0]
    if subcombo in types.keys():
            for subsubsubcombo in types[subcombo]:
                subcombonations.add((subsubsubcombo,))
    else:
                subcombonations.add((subcombo,))
    for subcombo in combo[1:]:
        if subcombo in types.keys():
            for subsubcombo in (subcombonations.copy(),subcombonations.clear())[0]:
                for subsubsubcombo in types[subcombo]:
                    subcombonations.add((*subsubcombo,subsubsubcombo))
        else:
            for subsubcombo in (subcombonations.copy(),subcombonations.clear())[0]:
                    subcombonations.add((*subsubcombo,subcombo))
    out.update(subcombonations)
    true_out = set()
    for combo in out:
        true_out.add(''.join(combo))
    return true_out


if __name__ == '__main__':
    N,M,L = tuple(map(int,input('').split(' ')))
    types = {}
    for _ in range(N):
        word, amount, *words = tuple(input('').split(' '))
        types[word] = words
    combonations = []
    for _ in range(M):
        combonations.append(brack_split(input('')))
    word = ''
    for _ in range(L):
        word+=input('')

    occure = []

    for combo in combonations:
        total = 0
        for subcombo in all_combonations(combo):
            if subcombo in word:
                total += 1
        occure.append(total)

    print('\n'.join(map(str,occure)))


'''
2 2 5
colour 6 or agent azure gules sable vert
motif 4 anchor grapes annulets ribbon
{motif}{colour}
escutcheon{colour}
thecapetowncoatofarmsisa
nerectanchorsablewithari
bbonazureandanescutcheon
guleschargedwiththreeann
uletsor
'''