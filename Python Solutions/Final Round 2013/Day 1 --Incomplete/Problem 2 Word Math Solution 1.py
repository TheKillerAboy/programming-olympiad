from itertools import product

def literal(str_,keys,values):
    out = str_
    for key, value in zip(keys,values):
        out = out.replace(key,str(value))
    return int(out)

if __name__ == '__main__':
    a = input('')
    b = input('')
    c = input('')

    left_elements = list({*a, *b})
    right_elements = list({*c})

    currect = 0

    for values in product(list(range(10)),repeat=len(left_elements)):
        try:
            right_literal = str(literal(a,left_elements,values)+literal(b,left_elements,values))
            if len(right_literal) == len(c):
                right_values = [-1 for i in range(len(right_elements))]
                for i, value in enumerate(right_literal):
                    index = right_elements.index(c[i])
                    if right_values[index] != -1:
                        raise Exception
                    right_values[index] = int(value)
                if -1 in right_values:
                    raise Exception
                left_right_correct = filter(lambda ele: ele in left_elements,right_elements)
                if all(map(lambda ele:right_values[right_elements.index(ele)] == values[left_elements.index(ele)],left_right_correct)):
                    currect+=1
        except:
            continue

    print(currect)