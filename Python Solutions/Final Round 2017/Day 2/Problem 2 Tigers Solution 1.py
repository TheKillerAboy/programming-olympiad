MOD = 10**9+7

def get_locs(start,distance,direction):
    for i in range(1,distance+1):
        loc = start+direction*i
        if loc in hills.keys():
            yield loc
        if loc == mi or loc ==ma:
            yield loc


def poss(start,direction):
    locs = list(get_locs(start,L,direction))
    if len(locs) == 0:
        return 1
    else:
        out = len(locs)
        for loc in locs:
            out *= poss(loc,direction)
            out %= MOD
        return out

def get_inputs():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    N,L = get_inputs()
    hills = {}
    top = (0,0)
    mi,ma = 9999999999,0
    for _ in range(N):
        l,h = get_inputs()
        mi = min(mi,l)
        ma = max(ma,l)
        hills[l] = h
        if h > top[1]:
            top = l , h
    mi -= 1
    ma += 1
    top = top[0]
    print((poss(top,-1)+poss(top,1))%MOD)