def factors(num):
    for i in range(1,num):
        if num % i == 0:
            yield i

if __name__ == '__main__':
    N = int(input('N? '))
    print(sum(list(factors(N))))

'''
N? 119451
'''