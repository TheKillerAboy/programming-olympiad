def perfectScore(number):
    out = 0
    for num in range(1,number):
        if number % num == 0:
            out+=num
    return out

if __name__ == '__main__':
    number = int(input('Input: '))
    if number < perfectScore(number):
        print('Abundant')
    elif number > perfectScore(number):
        print('Deficient')
    else:
        print('Perfect')