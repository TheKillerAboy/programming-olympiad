from string import ascii_lowercase

if __name__ == '__main__':
    letter = input('Input: ')
    size = ascii_lowercase.index(letter.lower())+1
    for _ in range(size):
        print(letter*size)

'''
Input: Z
'''