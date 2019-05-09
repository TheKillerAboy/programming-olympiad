import math

def get_stretch(time):
    value = math.sqrt(time)
    if math.floor(value) == value:
        return int(value-1)
    else:
        return math.floor(value)

def get_critical(stretch):
    return math.ceil((stretch**2+(stretch+1)**2)/2)

def is_bigger_than_critical(stretch):
    return stretch % 2 == 1

def add(tup1,tup2):
    x,y = tup1
    xo,yo = tup2
    return (x+xo,y+yo)

if __name__ == '__main__':
    time = int(input(''))
    stretch = get_stretch(time)
    critical = get_critical(stretch)
    location = (stretch+1,stretch+1)
    if is_bigger_than_critical(stretch):
        if time >= critical:
            location = add(location,(0,critical-time))
        else:
            location = add(location,(time-critical,0))
    else:
        if time >= critical:
            location = add(location,(critical-time,0))
        else:
            location = add(location,(0,time-critical))
    print(' '.join(map(lambda x:str(x),location)))