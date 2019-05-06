def get(variable_name):
    return float(input(f'{variable_name} = '))

if __name__ == '__main__':
    P = get('P')
    r = get('r')
    t = get('t')

    print(f'A = {P*(1+r*t/100)}')

'''
P = 10000
r = 6.75
t = 5.5
'''