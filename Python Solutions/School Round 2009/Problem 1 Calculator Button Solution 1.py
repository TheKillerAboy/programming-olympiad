def get_num(message):
    return int(input(message))

if __name__ == '__main__':
    num1 = get_num('First number: ')
    num2 = get_num('Second number: ')
    num_answer = get_num('Answer: ')
    operator = []
    if num1+num2==num_answer:
        operator.append('Plus only')
    if num1*num2==num_answer:
        operator.append('Times only')
    if len(operator) == 2:
        print('Plus or Times')
    elif len(operator) == 0:
        print('Neither Plus nor Times')
    else:
        print(operator[0])

'''
2 2 4
'''