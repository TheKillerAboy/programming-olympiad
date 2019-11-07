if __name__ == '__main__':
    amount = int(input('Input the number of buildings: '))
    heights = [int(_) for _ in input('Input building heights: ').split(' ')]
    heightest = max(heights)
    teleports = 0
    # left to middle
    current = heights[0]
    for height in heights[1:]:
        if height>current:
            current = height
            teleports+=1
        if height == heightest:
            break
    # right to middle
    current = heights[-1]
    for height in heights[::-1][1:]:
        if height>current:
            current = height
            teleports+=1
        if height == heightest:
            break
    print(f'The number of teleports is: {teleports}')

'''
20
1 15 9 7 11 7 4 25 3 17 12 31 13 33 100 120 2 150 200 500
'''