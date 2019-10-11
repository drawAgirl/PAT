from operator import attrgetter
class node:
    def __init__(self,id,score,location):
        self.id = id
        self.score = -score
        self.final_rank = 0
        self.location = location
        self.local_rank = 0
people = []
n=int(input())
for i in range(1,n+1):
    m=int(input())
    now = []
    for _ in range(m):
        id,score =input().split()
        people.append(node(id,int(score),i))
        now.append(people[-1])
    now.sort(key=attrgetter('score','id'))
    now[0].local_rank = 1
    rank = 2
    for i in range(1,len(now)):
        if now[i].score == now[i-1].score:
            now[i].local_rank = now[i-1].local_rank
        else:
            now[i].local_rank = rank
        rank += 1
people.sort(key=attrgetter('score','id'))
people[0].final_rank = 1
rank = 2
print(len(people))
print(people[0].id,people[0].final_rank,people[0].location,people[0].local_rank)
for i in range(1,len(people)):
    if people[i].score == people[i-1].score:
        people[i].final_rank = people[i-1].final_rank
    else:
        people[i].final_rank = rank
    rank += 1
    print(people[i].id, people[i].final_rank, people[i].location, people[i].local_rank)

