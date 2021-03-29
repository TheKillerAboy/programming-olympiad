import math
import time

def gen_primes(n):
    primes = [True]*(n+1)
    primes[1] = False
    for i in range(2,n+1):
        if primes[i]:
            for j in range(i*i,n+1,i):
                primes[j] = False
            yield i


def is_proper(n):
    for i in range(1,math.floor(math.sqrt(n))+1):
        if n%i == 0:
            if (i+n//i) not in primes:
                return False
    return True


inp = int(input())
start = time.time()

def delta():
    global start
    out = time.time()-start
    start = time.time()
    return out
primes = set(gen_primes(inp+1))
print('Got primes', delta())

pos = [False]*(inp+1)
pos[1] = True
for i in range(2,inp+1,4):
    pos[i] = True

for prime in primes:
    for j in range(2*prime*prime,inp+1,prime*prime):
        pos[j] = False
print('Initial check', delta())

out = 0
for i in range(inp+1):
    if i%1000000==0:
        print(f'Final Check: {i}', delta())
    if pos[i] and is_proper(i):
        out+=i
print(out)