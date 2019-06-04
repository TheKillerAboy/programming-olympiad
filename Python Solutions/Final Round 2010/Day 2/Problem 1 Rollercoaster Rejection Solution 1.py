from itertools import repeat

class Rollercoaster:
    def __init__(self):
        self.seats = [-1 for _ in range(size)]
        self.rejects = []

    def add(self,person, seat):
        if seat > size:
            self.rejects.append(person)
        elif self.seats[seat-1] != -1:
            self.add(person,seat+1)
        else:
            self.seats[seat-1] = person

if __name__ == '__main__':
    size, people = map(int,input('').split(' '))
    rollercoster = Rollercoaster()
    for person in range(1,people+1):
        seat = int(input(''))
        rollercoster.add(person,seat)
    print('\n'.join(map(str,rollercoster.rejects)))