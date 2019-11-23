from itertools import combinations

class Stadium:
    def __init__(self,trees):
        trees = list(trees)
        self.trees = trees.copy()
        xmin = min(trees,key=lambda tree:tree.x).x
        xmax = max(trees,key=lambda tree:tree.x).x
        ymin = min(trees,key=lambda tree:tree.y).y
        ymax = max(trees,key=lambda tree:tree.y).y
        self.top_left = min(trees,key=lambda tree:tree.distance((xmin,ymin)))
        trees.remove(self.top_left)
        self.bottom_right = min(trees,key=lambda tree:tree.distance((xmax,ymax)))
        trees.remove(self.bottom_right)
        self.bottom_left = min(trees,key=lambda tree:tree.x)
        trees.remove(self.bottom_left)
        self.top_right = trees[0]

    def size(self):
        width = min(self.top_right.x-self.top_left.x,self.bottom_right.x-self.bottom_left.x)
        height = min(self.bottom_left.y-self.top_left.y,self.bottom_right.y-self.top_right.y)
        return min(height,width)

    def __contains__(self, item):
        for tree1,tree2 in combinations(self.trees,2):
            if tree1.between(tree2,item):
                return True
        return False

class Tree:
    def __init__(self,loc):
        self.x,self.y = tuple(loc)

    def __iter__(self):
        yield self.x
        yield self.y

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __repr__(self):
        return f'x: {self.x} y: {self.y}'

    def distance(self,other):
        x,y = tuple(other)
        return (x-self.x)**2+(y-self.y)**2

    def between(self,other,between):
        return self.x<=between.x<=other.x and self.y<=between.y<=other.y


if __name__ == '__main__':
    trees = []
    N,W = tuple(map(int,input('').split(' ')))
    for _ in range(N):
        trees.append(Tree(tuple(map(int,input('').split(' ')))))
    MAX = 0
    for staduim in map(lambda trees:Stadium(trees),combinations(trees,4)):
        if len(list(filter(lambda tree:tree in staduim,set(trees).difference(staduim.trees)))) == 0:
            MAX = max(MAX,staduim.size())
    print(MAX)

'''
8 5
1 1
2 1
4 2
4 4
3 5
2 4
1 3
3 3
'''

'''
Primitive solution because it searches every combination of 4 trees and check's what size it can fix at max with no
trees in it
'''