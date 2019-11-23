def L(p, *args):
    out = []
    for row in p:
        out.append([])
        for val in row[::-1]:
            out[-1].append(val)
    return out


def T(p, *args):
    out = []
    for row in p[::-1]:
        out.append([])
        for val in row:
            out[-1].append(val)
    return out


def R(p, *args):
    width, height = tuple(args)
    out = []
    for c in range(width):
        out.append([])
        for r in range(height - 1, -1, -1):
            out[-1].append(p[r][c])
    return out


def print_pattern(p):
    for row in p:
        print(''.join(row))

if __name__ == '__main__':
    functions = {
        'L': L,
        'T': T,
        'R': R
    }
    width, height = int(input('Width: ')), int(input('Height: '))
    pattern = []
    print(f'Pattern of {width} by {height}:')
    for _ in range(height):
        line = input('')
        if len(line) < width:
            line = line + ' ' * (width - len(line))
        if len(line) > width:
            line = line[:width]
        pattern.append(list(line))
    sequance = input('Pattern Sequence(Separate with ", "): ').split(', ')
    for function in map(lambda x: functions[x], sequance):
        pattern = function(pattern, width, height)
    print_pattern(pattern)

'''
7
4
   O
  XXO
 OXXXO
XOOOXXX
R, T, L
'''
