from random import randint, choices
from itertools import combinations

def get_inputs(message = ''):
    return map(int,input(message).split(' '))

def make_combination_specific(specific_arangment, length):
    out = [[]]
    for i in range(length):
        use_arangement = i in specific_arangment
        for combo in (out.copy(), out.clear())[0]:
            if use_arangement:
                out.append((*combo, specific_arangment[i]))
            else:
                for j in range(1, K+1):
                    out.append((*combo, j))
    return out

def make_combination_groups(A_group, B_group, length):
    for b_indecs in combinations(set(range(length)) - set(A_group.keys()), len(B_group)):
        specific_arangment = A_group.copy()
        for index, value in zip(b_indecs, B_group):
            specific_arangment[index] = value
        yield from make_combination_specific(specific_arangment, length)


def AB_combinations(arangement, A, B):
    length = N
    for a_indecs in combinations(list(range(length)), A):
        A_group = {index: arangement[index] for index in a_indecs}
        for B_group in combinations(set(arangement) - set(A_group.values()), B):
            yield from make_combination_groups(A_group, B_group, length)

def bot(current):
    A_group = set()
    for i in range(N):
        if current[i] == find[i]:
            A_group.add(current[i])
    A = len(A_group)
    B = 0
    find_ = set(find)
    for value in current:
        if value in A_group:
            A_group.remove(value)
            find_.remove(value)
        elif value in find_:
            B+=1
            find_.remove(value)
    return A,B


if __name__ == '__main__':
    find = tuple(get_inputs('Play with: '))
    N , K = len(find),max(find)
    all_pos = set()
    current = tuple(randint(1,K) for _ in range(N))
    guesses = 1
    while True:
        print(current)
        A,B = bot(current)
        if N == A:
            print('Guesses: '+str(guesses))
            exit()
        print(A,B)
        if len(all_pos) == 0:
            all_pos = list(set(AB_combinations(current,A,B)))
        else:
            all_pos.remove(current)
            new_allpos = set(AB_combinations(current,A,B))
            all_pos = [pos for pos in all_pos if pos in new_allpos]
        current = choices(all_pos)[0]
        guesses += 1