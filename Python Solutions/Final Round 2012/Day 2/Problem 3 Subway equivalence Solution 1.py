from time import time
from itertools import combinations

class Connection:
    def __init__(self,fro,to):
        self.fro , self.to = fro,to

    def __hash__(self):
        return hash((self.fro,self.to))

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __repr__(self):
        return f'({self.fro},{self.to})'

class Alias:
    def __init__(self,fro,to):
        self.fro , self.to = fro,to

    def __eq__(self, other):
        return self.fro == other

class Network:
    def __init__(self):
        self.connections = set()
        self.aliases = []

    def add(self,other):
        self.connections.add(other)

    def add_alias(self,other):
        self.aliases.append(other)

    def get_alias(self,value):
        if value in self.aliases:
            return self.aliases[self.aliases.index(value)].to
        else:
            return value

    def has_aliases_fro(self):
        for alias in self.aliases:
            yield alias.fro

    def has_aliases_to(self):
        for alias in self.aliases:
            yield alias.to

    def equals(self):
        equal = set()
        for connection in self.connections:
            equal.add(Connection(self.get_alias(connection.fro),self.get_alias(connection.to)))
        return equal

    def __hash__(self):
        return hash(frozenset(self.equals()))

    def __eq__(self, other):
        return hash(self)==hash(other)

    def copy(self):
        empty = Network()
        empty.connections = self.connections.copy()
        empty.aliases = self.aliases.copy()
        return empty

    def __repr__(self):
        return ' '.join(map(str,self.equals()))

    def is_equivalent(self, netB):
        for connection in netB.connections:
            if connection.fro in netB.has_aliases_fro() and connection.to in netB.has_aliases_to():
                if Connection(netB.get_alias(connection.fro),netB.get_alias(connection.to)) not in self.connections:
                    return False
        return True

def is_same_network(netA,netB):
    subnetworks = [netB]
    length = 1
    while netA not in subnetworks and length<=size:
        subnetworks_copy = subnetworks.copy()
        subnetworks.clear()
        for network in subnetworks_copy:
            for i in range(size):
                for j in range(size):
                    if i not in network.has_aliases_fro() and j not in network.has_aliases_to():
                        subnet = network.copy()
                        subnet.add_alias(Alias(i,j))
                        if netA.is_equivalent(subnet):
                            subnetworks.append(subnet)
        length+=1

    return netA in subnetworks

def build_network(str):
    network = Network()
    movement = list(map(int,str))
    index = -1
    MAX = 0
    for move in movement:
        if move == 0:
            index += 1
            MAX+=1
            network.add(Connection(index,MAX))
        else:
            index -= 1
    return network

if __name__ == '__main__':
    amount = int(input(''))
    instructions = input('')
    size = int(len(instructions)/2+1)
    networks = set()
    networks.add(build_network(instructions))
    for _ in range(amount - 1):
        instructions = input('')
        networks.add(build_network(instructions))
    diffrences = 0
    start = time()
    for netA,netB in combinations(networks,r=2):
        if not is_same_network(netA,netB):
            diffrences+=1
    print(diffrences)

'''
3
00100111
00011011
00001111
'''

'''
To optimize this we need to improve the algorithm to see if two networks are the same thing
In other words improve is_same_network() method

currently a fluid fill method is used, with optimizing data structures like sets, and seeing if
two networks are somewhat equivalent, but it is very primitive
'''