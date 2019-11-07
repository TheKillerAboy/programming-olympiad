if __name__ == '__main__':
    top, bottom = tuple([int(_) for _ in input('top bottom: ').split(' ')])
    pattern_lenght = 1
    while (10**pattern_lenght-1)%bottom != 0:
        if pattern_lenght > bottom:
            break
        pattern_lenght+=1
    if pattern_lenght>bottom:
        print(top/bottom)
    else:
        left = str(top//bottom)
        right = str(top/bottom)[2:2+pattern_lenght]
        print(f'{left}.({right})')

'''
99 43
'''