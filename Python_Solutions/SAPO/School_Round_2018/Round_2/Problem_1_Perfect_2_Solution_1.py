def perfectScore(number):
    out = 0
    for num in range(1,number):
        if number % num == 0:
            out+=num
    return out

if __name__ == '__main__':
    num1, num2 = tuple([int(_) for _ in input('').split(' ')])
    out = [0,0,0]
    for num in range(num1, num2+1):
        if num < perfectScore(num):
            out[2]+=1
        elif num > perfectScore(num):
            out[0]+=1
        else:
            out[1]+=1
    print(' '.join([str(_) for _ in out]))