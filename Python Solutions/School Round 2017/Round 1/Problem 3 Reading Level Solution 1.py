from string import ascii_lowercase

if __name__ == '__main__':
    sentance = list(input('Input: '))
    for l, letter in enumerate(sentance):
        if letter.lower() not in ascii_lowercase:
            sentance[l] = ' '
    sentance = ''.join(sentance)
    sentance = sentance.replace('  ','')
    if sentance[-1] == ' ':
        sentance = sentance[:-1]
    sentance = sentance.split(' ')
    print(sum(map(lambda word:len(word),sentance))/len(sentance))

'''
“Stop!”, shouted Chris. He said to Emily, “Why were you running in the hall?”
'''