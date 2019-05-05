if __name__ == '__main__':
    day,even,weekend = tuple([int(_) for _ in input('Input: ').split(' ')])
    price = 0
    #daytime
    if day > 100:
        price+=(day-100)*80
    price+=even*70
    price+=weekend*50
    print(f'{price}c')