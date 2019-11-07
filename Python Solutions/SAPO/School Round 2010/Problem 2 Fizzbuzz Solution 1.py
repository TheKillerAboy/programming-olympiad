if __name__ == '__main__':
    upper = int(input('Count to what number? '))
    for i in range(1,upper+1):
        if i % 15 == 0:
            print('fizzbuzz')
        elif i % 5 == 0:
            print('buzz')
        elif i % 3 == 0:
            print('fizz')
        else:
            print(i)

'''
32
'''