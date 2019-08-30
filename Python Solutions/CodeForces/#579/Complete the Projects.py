class Project:
    def __init__(self,needed,score):
        self.needed = needed
        self.score = score

    def __hash__(self):
        return hash((self.needed,self.score))

    def __eq__(self, other):
        return hash(self) == hash(other)

class ProjectsList:
    def __init__(self,rating,projects_to_complete,completed):
        self.rating = rating
        self.ptc = projects_to_complete
        self.completed = completed

    def next(self):
        for project in self.ptc:
            if project.needed <= self.rating:
                ptc_copy = self.ptc.copy()
                ptc_copy.remove(project)
                yield ProjectsList(self.rating+project.score,ptc_copy,self.completed+1)


if __name__ == '__main__':
    n,r = map(int,input('').split(' '))
    projects = [Project(*map(int,input('').split(' '))) for _ in range(n)]
    lists = [ProjectsList(r,projects,0)]
    completed = 0
    while len(lists) > 0:
        completed = max(map(lambda list:list.completed,lists))
        for list in (lists.copy(),lists.clear())[0]:
            lists.extend(list.next())
    print(completed)