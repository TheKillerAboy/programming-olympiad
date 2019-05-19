from fractions import Fraction

if __name__ == '__main__':
    rationals = set()
    N = int(input('N = '))
    for i in range(1,N+1):
        for j in range(i+1):
            rationals.add(Fraction(j,i))
    print(len(rationals))

'''
100
'''