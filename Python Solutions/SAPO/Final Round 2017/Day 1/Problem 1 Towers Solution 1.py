def get_inputs():
    return map(int,input('').split(' '))

if __name__ == '__main__':
    N,M = get_inputs()
    cities = list(get_inputs())
    towers = set(get_inputs())
    min_distance = 0
    for city in cities:
        distance = 0
        left = city
        right = city
        while left not in towers and right not in towers:
            distance += 1
            left -= 1
            right += 1
        min_distance = max(min_distance,distance)
    print(min_distance)