def can_clock_rounddance(people,amount):
    for prev, next in zip(people[:-1],people[1:]):
        if prev != next - 1:
            if prev != amount:
                return False
    return True

def can_counterclock_rounddance(people,amount):
    for prev, next in zip(people[:-1],people[1:]):
        if prev != next+1:
            if prev != 1:
                return False
    return True

if __name__ == '__main__':
    queries = int(input(''))
    for amount, people in [(int(input('')),list(map(int,input('').split(' ')))) for _ in range(queries)]:
        print('YES' if (can_clock_rounddance(people,amount) or can_counterclock_rounddance(people,amount)) else 'NO')