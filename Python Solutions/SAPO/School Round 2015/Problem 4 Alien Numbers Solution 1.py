from itertools import count

def factorial(num):
    out = 1
    for i in range(2,num+1):
        out*=i
    return out

def get_upper(num):
    for i in count(1):
        if factorial(i) > num:
            return i

if __name__ == '__main__':
    num = int(input('Input: '))
    factorials = []
    upper = get_upper(num)
    for i in range(upper-1,0,-1):
        factorials.append(num//factorial(i))
        num-=factorials[-1]*factorial(i)
    print(' '.join([str(_) for _ in factorials[::-1]]))

'''
2100100100
'''