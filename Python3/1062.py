# attrgetter构造类的方法稍微快一点
class student:
    def __init__(self,id,virtue,talent,rank):
        self.id = id
        self.virtue = virtue
        self.talent = talent
        self.rank = rank
        self.total = -(self.virtue + self.talent)
        self.fu_virtue = -virtue
#     def __repr__(self):
#         return repr((self.id,self.virtue,self.talent,self.rank,self.total,self.fu_virtue))

N,L,H = map(int,input().split())
from operator import attrgetter,itemgetter
cnt = 0
people = []
for _ in range(N):
    id,virtue,talent =map(int,input().split())
    if virtue <L  or talent < L:
        continue
    elif virtue >=H  and talent >= H:
        rank = 1
    elif virtue >= H and talent < H:
        rank = 2
    elif virtue>= talent:
        rank = 3
    else:
        rank = 4
    temp = student(id,virtue,talent,rank)
    # people.append([id,-virtue,talent,rank,-(virtue+talent)])
    people.append(temp)
people = sorted(people,key=attrgetter('rank','total','fu_virtue','id'))
# people.sort(key=itemgetter(3,4,1,0))
print(len(people))
for each in people:
    print("%d %d %d"%(each.id,each.virtue,each.talent))
# print(len(people))
# for each in people:
#     print("%d %d %d"%(each[0],-each[1],each[2]))