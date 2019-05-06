if __name__ == '__main__':
    message = input('Input: ')
    message+=' '*(len(message)%5)
    message = message.replace(' ','.')
    message=list(message)
    encrypted = ''
    vertical = len(message)//5
    for i in range(5):
        for j in range(vertical):
            index = j*5 + i
            encrypted+=message[index]
    print(encrypted)

'''
T.GLEHC.L.EACEM.THDAR.A.LATSATTHET!.EDE.T....HDKT.EOIH
'''