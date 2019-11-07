from itertools import count

primes = {2,3,5}
maxprime = 5

def next_attempt_prime(attempt_prime):
    attempt_prime+=2
    if attempt_prime % 5 == 0:
        attempt_prime+=2
    return attempt_prime

def is_prime(number):
    global maxprime
    if number <= maxprime:
        return number in primes
    else:
        for prime in primes:
            if number % prime == 0:
                return False
        attemp_prime = maxprime
        while attemp_prime<=number:
            attemp_prime = next_attempt_prime(attemp_prime)
            isPrime = True
            for prime in primes:
                if attemp_prime % prime == 0:
                    isPrime = False
                    break
            if isPrime:
                primes.add(attemp_prime)
                maxprime = attemp_prime
                if attemp_prime == number:
                    return True
                elif number % attemp_prime:
                    return False
    return False

def factors(num):
    for i in range(1,num+1):
        if num % i == 0:
            yield i

def all_factor_prime(num):
    for factor in factors(num):
        factor = factor + num//factor
        if not is_prime(factor):
            return False
    return True

def upto(upper):
    yield 1
    for i in count(start=2,step=4):
        if i > upper:
            break
        yield i

if __name__ == '__main__':
    upper = int(input('Input: '))
    total = 0
    for i in upto(upper):
        if i % 10000:
            print(i)
        if all_factor_prime(i):
            total+=i
    print(total)

'''
10000

The hardest one is 100000000
'''