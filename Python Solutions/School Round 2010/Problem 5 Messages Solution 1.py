def nCr(n,k):
    top = 1
    for i in range(n-k,n+1):
        top*=i
    lower = 1
    for i in range(2,k):
        lower*=i
    return top//lower

def combonations(n,k):
    return nCr(n,k)//(n+1-k)

if __name__ == '__main__':
    lenght = int(input('How many letters in the message? '))
    total = 0
    for i in range(1,lenght):
        total = (total+combonations(lenght-1,i))%10007
    print(total)

'''
How many letters in the message? 2010
'''