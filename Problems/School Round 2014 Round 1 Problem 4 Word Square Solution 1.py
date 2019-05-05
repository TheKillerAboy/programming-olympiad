square = '''T H E Q T T E P
L R E K A W R E
T S E T N O C I
X Y C O L T Z J
R C H I L E S Q
U M N X B E S T
Y X K O O C Q F
G H I K C O R B'''
square = [row.replace(' ','') for row in square.split('\n')]

if __name__ == '__main__':
    word = input('Input: ')
    #forwards search
    for r, row in enumerate(square):
        if word in row:
            print(f'{word}, row {r+1}, column {row.index(word)+1}, forward')
            exit()
    #backwards search
    for r, row in enumerate(map(lambda row:row[::-1],square)):
        if word in row:
            print(f'{word}, row {r+1}, column {row.index(word)+len(word)-1}, backwards')
            exit()