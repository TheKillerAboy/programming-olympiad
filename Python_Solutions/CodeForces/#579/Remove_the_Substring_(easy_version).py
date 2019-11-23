def get_all_lefts(word,substring):
    if len(substring) == 0:
        yield ((len(word),word),)
    else:
        if substring[0] not in word:
            yield (-1,)
        else:
            for i in range(len(word)):
                if word[i] == substring[0]:
                    for sub_sequance in get_all_lefts(word[i+1:],substring[1:]):
                        yield ((i,word[:i]),*sub_sequance)

if __name__ == '__main__':
    word = input('')
    substring = input('')
    maxNum = 0
    for lefts in map(list,get_all_lefts(word,substring)):
        if -1 in lefts:
            continue
        print(lefts)
    print(maxNum)