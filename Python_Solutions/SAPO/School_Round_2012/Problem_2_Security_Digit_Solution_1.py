if __name__ == '__main__':
    number = input('Input: ')
    while len(number) != 1:
        temp = 1
        for num in map(lambda x:int(x),filter(lambda x:x!='0',number)):
            temp *= num
        number = str(temp)
    print(number)

'''
1567890123
'''