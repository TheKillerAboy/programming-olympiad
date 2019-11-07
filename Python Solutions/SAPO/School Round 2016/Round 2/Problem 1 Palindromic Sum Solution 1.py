def next_palindromic(num):
    return num+int(str(num)[::-1])

if __name__ == '__main__':
    num = int(input('Input: '))
    iterations = 0
    while str(num) != str(num)[::-1]:
        num = next_palindromic(num)
        iterations+=1
    print(iterations)