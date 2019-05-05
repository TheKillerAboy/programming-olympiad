if __name__ == '__main__':
    word = input('Input: ')
    triangle = []
    for _ in range(len(word)):
        triangle.append(list(' '*(2*len(word)-1)))
    # left
    for l, letter in enumerate(word):
        triangle[l][len(word)-1-l] = letter
    # bottom
    for l, letter in enumerate(word):
        triangle[-1][2*l] = letter
    # right
    for l, letter in enumerate(word[::-1]):
        triangle[l][len(word)-1+l] = letter
    for row in triangle:
        print(''.join(row))

'''
CUBIC
'''