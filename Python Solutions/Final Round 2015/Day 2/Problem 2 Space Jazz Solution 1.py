def remove_dubbel(word):
    index = 0
    while index < len(word)-1:
        if word[index] == word[index+1]:
            word = word[:index]+word[index+2:]
        else:
            index += 1
    if len(word) == 2 and word[0] == word[1]:
        return ''
    return word

def add_dubbles(word):
    yield word[0]*2 + word[1:]
    for i in range(1,len(word)-1):
        yield word[:i]+word[i]*2+word[i+1:]
    yield word[:len(word)] + word[-1]*2

if __name__ == '__main__':
    words = {input('')}
    words = set(map(remove_dubbel,words))
    counter = 0
    while '' not in words:
        counter += 1
        for word in (words.copy(),words.clear())[0]:
            words.update(add_dubbles(word))
        words = set(map(remove_dubbel,words))
    print(counter)

'''
aagog
'''
