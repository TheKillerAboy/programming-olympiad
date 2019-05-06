if __name__ == '__main__':
    terms = [int(_) for _ in input('Start with: ').split(' ')]
    N = int(input('N: '))
    for i in range(len(terms),N):
        end = sum(terms)
        for j in range(len(terms)-1):
            terms[j]=terms[j+1]
        terms[-1] = end
    print(terms[-1])

'''
2 8 15 4 4 3 8 9 10 3
36
'''