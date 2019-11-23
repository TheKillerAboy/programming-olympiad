if __name__ == '__main__':
    indexs = []
    values = []
    marbles = list(input('Input the marbles: '))
    for marble in marbles:
        if marble not in indexs:
            indexs.append(marble)
            values.append(marble)
        else:
            values[indexs.index(marble)]+=marble
    values.sort(key = lambda group:len(group),reverse=True)
    print(''.join(values))

'''
dfadccabbcdfdcfacedad
'''