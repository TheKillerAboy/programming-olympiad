def calculator(equation):
    if '(' in equation:
        equation = str(calculator(equation[equation.index('(')+1:equation.rindex(')')]))+equation[equation.rindex(')')+1:]
    if '*' in equation:
        return int(equation[:equation.index('*')])*int(equation[equation.index('*')+1:])
    elif '+' in equation:
        return int(equation[:equation.index('+')]) + int(equation[equation.index('+') + 1:])


def all_forms(lst):
    for i in range(len(lst)):
        combo = [j for ind,j in enumerate(lst) if ind != i]
        if len(lst)>2:
            for out in all_forms(combo):
                yield '('+out + f')+{lst[i]}'
                yield '('+out + f')*{lst[i]}'
        if len(lst)==2:
            x,y = tuple(lst)
            yield f'{x}+{y}'
            yield f'{x}*{y}'

def is_same(eq1,eq2):
    if '+' not in eq1 and '+' not in eq2:
        return True
    if '*' not in eq1 and '*' not in eq2:
        return True
    if eq1==eq2:
        return True
    return False

if __name__ == '__main__':
    equations = []
    input_numbers = [int(_) for _ in input('What numbers do you have? ').split(' ')]
    for equation in all_forms(input_numbers):
        isnotIn = True
        for eq in equations:
            if is_same(eq,equation):
                isnotIn = False
                break
        if isnotIn:
            equations.append(equation)
    numbers = set()
    for equation in equations:
        numbers.add(calculator(equation))

    print(f'You can form {len(numbers)} numbers')
    print(f'Their sum is {sum(numbers)}')

'''
What numbers do you have? 15 37 26 1001 32
'''