def gcd(a,b):
    if a%b != 0:
        return gcd(b,a%b)
    else:
        return b

def get_divsors_amount(value):
    output_pre = []
    current = value
    for i in range(2,value+1):
        if(current%i == 0):
            output_pre.append(i)
            current /= i
        if current == 1:
            break
    output = 1
    for unique in set(output_pre):
        output*=output_pre.count(unique)+1
        output_pre.remove(unique)
    return output

if __name__ == '__main__':
    amount = int(input(''))
    sequance = list(map(int,input('').split(' ')))
    gcdall = sequance[0]
    for value in sequance[1:]:
        gcdall = gcd(*sorted([gcdall,value]))
    print(get_divsors_amount(gcdall))