if __name__ == '__main__':
    N = int(input(''))
    codes = tuple(map(int,input('').split(' ')))
    special = (23,87,56,77)
    for i in range(N-4):
        diffs = set(map(lambda a,b : a - b,codes[i:i+4],special))
        if len(diffs) == 1:
            print(next(iter(diffs)))
            exit()