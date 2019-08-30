def get_unique(parent,boxers):
    if len(boxers) != 0:
        for i in range(len(boxers)):
            boxers_copy = boxers.copy()
            del boxers_copy[i]
            if boxers[i]+1 not in parent:
                return get_unique([*parent,boxers[i]+1],boxers_copy)
            if boxers[i] not in parent:
                return get_unique([*parent,boxers[i]],boxers_copy)
            if boxers[i]-1 not in parent and boxers[i]-1>0:
                return get_unique([*parent,boxers[i]-1],boxers_copy)
    return parent

if __name__ == '__main__':
    n = int(input(''))
    boxers = list(map(int,input('').split(' ')))
    print(len(get_unique([],boxers)))