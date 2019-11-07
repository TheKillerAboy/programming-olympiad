from math import log2, ceil

def factor_2_jump(number):
    if number == 0:
        return 0
    log2num = log2(number)
    upper = ceil(log2num)
    if upper == log2num:
        return 1
    elif 2**upper <= MAX and 2**upper-number<number-2**(upper-1):
        return 1 + factor_2_jump(2**upper-number)
    else:
        return 1 + factor_2_jump(number-2**(upper-1))

def fox_jumps(a,b,c):
    return factor_2_jump(a-1)+factor_2_jump(b-1)+factor_2_jump(c-1)

def get_input():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    MAX, fox_amount = get_input()
    foxs = [tuple(get_input()) for _ in range(fox_amount)]
    total = 0
    for i in range(1,MAX+1):
        for j in range(1,MAX+1):
            for k in range(1,MAX+1):
                total+=fox_jumps(i,j,k)
    print(total)
    for fox in foxs:
        print(fox_jumps(*fox))

'''
3 4
2 1 2
2 3 3
1 1 1
3 3 3
'''