def subwords(word,size):
    index = 0
    words = 1
    for i in range(0,len(word),size):
        sub_index = i
        sub_words = 1
        word_ = word[i:i+size]
        for j in range(i+size,len(word),size):
            if word[j:j+size] == word_:
                sub_words+=1
            else:
                break
        if sub_words>words:
            words=sub_words
            index = sub_index
    return words, index

def shorten_word(word):
    for size in range(int(len(word)/2),1,-1):
        words,index = subwords(word,size)
        if words > 1:
            return f'{word[:index]}{words}({word[index:index+size]}){word[index+words*size:]}'
    return word

def shortest_word(word):
    sw =  shorten_word(word)
    if sw == word:
        return word
    else:
        return sw[:sw.index('(')+1]+shortest_word(sw[sw.index('(')+1:sw.index(')')])+sw[sw.index(')'):]

if __name__ == '__main__':
    print(shortest_word(input('')))