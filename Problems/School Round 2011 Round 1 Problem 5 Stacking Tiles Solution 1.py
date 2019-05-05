class Stack:
    def __init__(self,path,height):
        self.path , self.height = path,height

    def next(self,tile):
        w,h = tile
        if w<self.path[-1]:
            yield Stack([*self.path,w],self.height+h)
        if h<self.path[-1]:
            yield Stack([*self.path,h],self.height+w)
        yield self

    def __repr__(self):
        # path variable is used instead of just saving the last base to troubleshoot the path used
        return f'path: {", ".join([str(_) for _ in self.path])}; height: {self.height}'

if __name__ == '__main__':
    tile_amount = int(input('Input the number of tiles: '))
    _tiles = input('Input the tiles\' width and heights: ').split(' ')
    tiles = []
    for i in range(tile_amount):
        x,y = _tiles[2*i],_tiles[2*i+1]
        tiles.append((int(x),int(y)))
    stacks = [Stack([99],0)]
    # to get the max possible height, you could use permutations from the itertools library and
    # substitute   <>   the tiles below with every permutation and get the heights.
    # it is 27 for the example in the question
    for tile in tiles[1:]:
        stacks_copy = stacks.copy()
        stacks.clear()
        for stack in stacks_copy:
            for next_stack in stack.next(tile):
                stacks.append(next_stack)
    maxheight = max(stacks,key=lambda stack:stack.height).height
    print(maxheight)

'''
10
9 10 13 18 13 12 1 18 16 8 11 17 8 19 3 15 2 12 1 4
'''