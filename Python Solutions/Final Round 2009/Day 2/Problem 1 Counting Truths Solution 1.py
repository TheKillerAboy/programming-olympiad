def get_input():
    return int(input(''))

def get_truths(amount):
    new_amount = len([truth for truth in truths if truth <= amount])
    if new_amount > amount:
        return get_truths(new_amount)
    else:
        return amount

if __name__ == '__main__':
    amount = get_input()
    truths = [get_input() for _ in range(amount)]
    print(get_truths(min(truths)))