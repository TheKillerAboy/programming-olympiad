if __name__ == '__main__':
    kinds = int(input('How many kinds? '))
    marbles = [int(_) for _ in input('Marbles? ').split(' ')]
    needed = max(marbles)*len(marbles) - sum(marbles)
    print(needed)

'''
How many kinds? 5
Marbles? 1 2 7 3 4
'''