from itertools import combinations

def get_allrects(values):
    if len(values) == 2:
        yield [tuple(values)]
    else:
        for i in range(len(values)-1):
            for j in range(i+1,len(values)):
                values_copy = values.copy()
                a,b = values_copy[i],values_copy[j]
                del values_copy[i]
                del values_copy[j-1]
                for rects in get_allrects(values_copy):
                    yield [(a,b),*rects]

def can_make_equal_rectangles(n,sticks):
    unique = set()
    pairs = []
    for value in sticks:
        if(value in unique):
            unique.remove(value)
        else:
            pairs.append(value)
            unique.add(value)
    for rects_group in get_allrects(pairs):
        area = rects_group[0][0]*rects_group[0][1]
        if len(list(filter(lambda rect: rect[0]*rect[1]!=area,rects_group[1:]))) == 0:
            return True
    return False

if __name__ == '__main__':
    queries = int(input(''))
    for n, sticks in [(int(input('')),map(int,input('').split(' '))) for _ in range(queries)]:
        print('YES' if can_make_equal_rectangles(n,sticks) else 'NO')