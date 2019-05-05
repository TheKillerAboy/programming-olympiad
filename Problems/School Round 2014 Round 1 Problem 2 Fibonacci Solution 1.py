if __name__ == '__main__':
    F = int(input('F = '))
    S = int(input('S = '))
    L = int(input('L = '))
    print(f"{F}, ",end='')
    for _ in range(L-2):
        middel = F
        F = S
        S = middel + S
        print(f"{F}, ", end='')
    print(f"{S}")

'''
F = -2
S = 3
L = 12
'''