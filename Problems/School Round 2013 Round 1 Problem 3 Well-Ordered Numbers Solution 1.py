from itertools import combinations

def tuple_to_num(inp):
    mul = 1
    out = 0
    for num in list(inp)[::-1]:
        out += mul*num
        mul*=10
    return out

if __name__ == '__main__':
    size = int(input('Input: '))
    sum = 0
    for num in map(lambda x:tuple_to_num(x),combinations(range(1,10),size)):
        sum+=num
    print(sum)