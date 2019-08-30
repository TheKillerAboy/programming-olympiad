def combos_word(orders,combo,word):
    out = ''
    for type, sub in word:
        if type == 'w':
            out+= sub
        else:
            out+=combo[orders.index(sub)]
    return out

def getAllCombintions(inter):
    orders = []
    word = []
    while '{' in inter:
        orders.append(inter[inter.index('{')+1:inter.index('}')])
        word.append(('w',inter[:inter.index('{')]))
        word.append(('o',orders[-1]))
        inter = inter[inter.index('}')+1:]
    all_combos = [[_] for _ in replacingWords[orders[0]]]
    current = 1
    while current < len(orders):
        for combo in (all_combos.copy(),all_combos.clear())[0]:
            for new in replacingWords[orders[current]]:
                all_combos.append([*combo,new])
        current+=1
    return map(lambda combo:combos_word(orders,combo,word),all_combos)



if __name__ == '__main__':
    N,M,L = map(int,input('').split(' '))
    replacingWords = {}
    for _ in range(N):
        inputs = input('').split(' ')
        replacingWords[inputs[0]] = inputs[2:]
    interChanging = [input('') for _ in range(M)]
    para = ''.join([input('') for _ in range(L)])
    output = []
    for inter in interChanging:
        output.append(0)
        for word in getAllCombintions(inter):
            if word in para:
                output[-1]+=1
    print('\n'.join(map(str,output)))