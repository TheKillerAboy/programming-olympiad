def change_sentance():
    for l, letter in enumerate(sentance):
        if letter.lower() in change.keys():
            if letter.islower():
                sentance[l] = change[letter.lower()]
            else:
                sentance[l] = change[letter.lower()].upper()

if __name__ == '__main__':
    change = dict(a='j',e='k',i='q',o='x',u='z')
    sentance = list(input('Input: '))
    change_sentance()
    change = {value:key for key,value in change.items()}
    change_sentance()
    print(''.join(sentance))

'''
Look at my book. Is it the junior version?
'''