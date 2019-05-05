from string import ascii_uppercase
console = list(ascii_uppercase)
console.extend([' ','-','.','Accept'])

def position(a):
    return console.index(a)%6, console.index(a)//6

def cost(a,b):
    ax,ay = position(a)
    bx,by = position(b)
    return abs(ax-bx) + abs(ay-by) + 1

if __name__ == '__main__':
    sentance = list(input('Input: '))
    path = ['A',*sentance,'Accept']
    distance = 0
    for current, next in zip(path[:-1],path[1:]):
        distance+=cost(current,next)
    print(distance)

'''
DOMO ARIGATO MR. ROBOTO
'''