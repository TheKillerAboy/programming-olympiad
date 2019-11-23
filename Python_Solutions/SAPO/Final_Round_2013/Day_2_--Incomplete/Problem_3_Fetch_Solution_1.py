def get_sigma(sequance):
    avg = sum(sequance)/len(sequance)
    out = 0
    for value in sequance:
        out += (avg-value)**2
    out/= len(sequance)
    out = out ** 0.5
    return out

if __name__ == '__main__':
    N,T = map(int,input('').split(' '))
    sequance = [int(input('')) for _ in range(N)]
    print(get_sigma(sequance))