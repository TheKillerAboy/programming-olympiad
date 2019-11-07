def finding_nearest(index):
    value = heights[index]
    for i in range(1,max(length-index,index+1)):
        if 0<=index-i:
            if heights[index-i] == value:
                return i
        if index+i<length:
            if heights[index+i] == value:
                return i
    return -1

if __name__ == '__main__':
    length = int(input(''))
    heights = list(map(int,input('').split(' ')))
    print(' '.join(map(str,map(finding_nearest,range(length)))))

'''
6
2 1 2 5 1 2
'''