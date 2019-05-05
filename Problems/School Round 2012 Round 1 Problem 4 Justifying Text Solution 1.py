sentence = 'A great discovery solves a great problem but there is a grain of discovery in the solution of any problem'
words = sentence.split(' ')

def total_len(current_words):
    out = 0
    for word in current_words:
        out+=len(word)
    return out

def print_justify(current_words):
    leftover = width - (total_len(current_words) + len(current_words) - 1)
    for _ in range(len(current_words) - 1):
        current_words[_] += ' '
    if len(current_words)>1:
        for subindex in range(leftover):
            current_words[subindex % (len(current_words) - 1)] += ' '
    print(''.join(current_words))

if __name__ == '__main__':
    width = int(input('Width? '))
    index  = 0
    current_words = [words[0]]
    while index < len(words)-1:
        if total_len([*current_words,words[index+1]])+len(current_words)-1< width:
            current_words.append(words[index+1])
            index+=1
        else:
            print_justify(current_words)
            current_words = []
    print_justify(current_words)

'''
10
'''