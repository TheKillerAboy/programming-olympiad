def factors(num):
    for i in range(1,num+1):
        if num % i == 0:
            yield i

primes = {2,3,5}

def divides_any(num):
    for prime in primes:
        if num % prime == 0:
            return True
    return False

def isPrime(num):
    if num in primes:
        return True
    elif num < max(primes):
        return False
    else:
        for i in range(max(primes)+2,num+1):
            if not divides_any(i):
                primes.add(i)
        return num in primes


def isGoodPrime(num):
    for factor in factors(num):
        if not isPrime(factor+num//factor):
            return False
        if factor > num // 2:
            return True

if __name__ == '__main__':
    sum = 1
    MAX = int(input(''))
    for i in range(2,MAX+1,4):
        if ((i - 2)//4) % 10000 == 0:
            print(i,': ',len(primes))
        if isGoodPrime(i):
            sum+=i
    print(sum)
