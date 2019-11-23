if __name__ == '__main__':
    length = int(input(''))
    pattern = [int(_) for _ in input('').split(' ')]
    for size in range(2,length+1):
        patterns = set()
        for start in range(0,length,size):
            pat = []
            current_pattern = pattern[start:start+size+1]
            if len(current_pattern)==size+1:
                for prev, next in zip(current_pattern[:-1],current_pattern[1:]):
                    pat.append(next-prev)
                patterns.add(tuple(pat))
        patterns = list(patterns)
        if len(patterns) == 1:
            if patterns[0][0]==patterns[0][1] and len(patterns[0]) == 2:
                patterns[0] = [patterns[0][0]]
            print(' '.join(map(str,patterns[0])))
            exit()

'''
25
4 10 7 5 11 8 6 12 9 7 13 10 9 15 12 10 16 13 11 17 14 12 18 15 14
'''