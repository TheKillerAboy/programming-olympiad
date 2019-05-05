if __name__ == '__main__':
    c= [3,5,7]
    laps = int(input(''))
    time = 0
    for _ in range(laps):
        time+=min(c)
        c[c.index(min(c))]+=1
    print(time)

'''
25
'''