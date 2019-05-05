def isOrdered(num):
    prev = 0
    for num in map(lambda num :int(num),list(str(num))):
        if num < prev:
            return False
        else:
            prev = num
    return True

if __name__ == '__main__':
    V = int(input('V = '))
    sequance = map(lambda num:num**2,range(V))
    print(', '.join(map(lambda x:str(x),filter(isOrdered,sequance))))