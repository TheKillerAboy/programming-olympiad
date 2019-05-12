if __name__ == '__main__':
    S, P = tuple(map(int,input('').split(' ')))
    pirates = [0 for i in range(P)]
    split = P//2
    if split == P/2:
        split-=1
    if S > split:
        pirates[0] = S - split
        for i in range(P-1,P-1-split,-1):
            pirates[i] = 1
    else:
        pirates[1] = S
        pirates[0] = -1

    for pirate in pirates:
        print(pirate)