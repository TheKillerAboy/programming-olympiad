def get_amount(word,letter):
    amount = 0
    for let in word:
        if let == letter:
            amount+=1
    return amount

if __name__ == '__main__':
    word = list(input('Input: '))
    unique = []
    for letter in word:
        if letter not in unique:
            unique.append(letter)
    amounts = []
    for letter in unique:
        amounts.append(get_amount(word,letter))
    print(''.join(map(lambda letter,amount:letter+str(amount),unique,amounts)))

'''
mississippi
'''