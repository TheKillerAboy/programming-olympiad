import math

def gen_primes(n):
    primes = [True]*(n+1)
    primes[1] = False
    for i in range(2,n+1):
        if primes[i]:
            for j in range(i*i,n+1,i):
                primes[j] = False
            yield i


def is_proper(n):
    out = True
    for i in range(2,math.floor(math.sqrt(n))+1):
        if n%i == 0:
            if (i+n//i) not in primes:
                out = False
    return out

inp = int(input())
primes = list(gen_primes(inp+1))

pos = [False]*(inp+1)
pos[1] = True
for i in range(2,inp+1,4):
    pos[i] = True

for prime in primes:
    for j in range(2*prime*prime,inp+1,prime*prime):
        pos[j] = False

out = 0
for i in range(inp+1):
    if pos[i] and is_proper(i):
        out+=i
print(out)