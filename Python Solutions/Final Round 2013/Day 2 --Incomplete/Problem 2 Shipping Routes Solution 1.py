class Routes(list):
    def __init__(self):
        super().__init__()

    def containing(self,port):
        for x,y in self:
            if x == port:
                yield y, (x,y)
            elif y == port:
                yield x, (x,y)


class Path:
    def __init__(self,location,searched,distance = 0):
        self.location,self.distance,self.searched = location,distance,searched

    def __hash__(self):
        return hash(self.location)

    def __eq__(self, other):
        return hash(self) == hash(other)

if __name__ == '__main__':
    n_ports, n_routes = tuple(map(int,input('').split(' ')))
    routes = Routes()
    for _ in range(n_routes):
        routes.append(tuple(map(int,input('').split(' '))))
    fluided = set()
    circuit = set()
    for port in range(1,n_ports+1):
        if port not in fluided:
            current_visits = {Path(port,set())}
            all_visits = current_visits.copy()
            while len(current_visits) > 0 and max(current_visits,key=lambda visit:visit.distance).distance < n_ports+1 and len(list(filter(lambda visit:visit.location == port and visit.distance != 0,current_visits))) == 0 or len(all_visits) == 1:
                current_visits_copy = current_visits.copy()
                current_visits.clear()
                for visit in current_visits_copy:
                    for next, connection in routes.containing(visit.location):
                        if connection not in visit.searched:
                            next_path = Path(next,{*visit.searched,connection},distance=visit.distance+1)
                            current_visits.add(next_path)
                            all_visits.add(next_path)
            if len(list(filter(lambda visit:visit.location == port and visit.distance != 0,current_visits))) != 0:
                visit = list(filter(lambda visit:visit.location == port and visit.distance != 0,current_visits))[0]
                traveled = set()
                for rout in visit.searched:
                    traveled.update({*rout})
                fluided.update(traveled)
                circuit.update(traveled)
            else:
                fluided.add(port)
    print('\n'.join(map(str,set(range(1,n_ports+1))-circuit)))

'''
5 5
4 5
5 2
2 4
1 3
3 2
'''