from operator import attrgetter
n,m,k=map(int,input().split())
quota = list(map(int,input().split()))
ans =[[] for i in range(m)]
people = []
class node:
    def __init__(self,id,exam,view,school):
        self.exam = exam
        self.view = view
        self.total = (self.exam + self.view)/2
        self.school = school
        self.rank = 0
        self.id = id
for i in range(n):
    exam,view,*school = map(int,input().split())
    cur = node(i,exam,view,school)
    people.append(cur)
people.sort(key=attrgetter('total','exam'),reverse=True)
rank = 2
people[0].rank = 1
for i in range(1,n):
    if people[i].total != people[i-1].total:
        people[i].rank = rank
    else:
        if people[i].exam != people[i-1].exam:
            people[i].rank = rank
        else:
            people[i].rank = people[i-1].rank
    rank += 1
quota[people[0].school[0]] -=1
school_rank = [0 for i in range(m)]
school_rank[people[0].school[0]] = 1
ans[people[0].school[0]].append(people[0].id)
for i in range(1,n):
    for one in people[i].school:
        if quota[one] > 0:
            quota[one] -= 1
            ans[one].append(people[i].id)
            school_rank[one] = max(school_rank[one],people[i].rank)
            break
        else:
            if school_rank[one] == people[i].rank:
                quota[one] -= 1
                ans[one].append(people[i].id)
                break
for i in range(m):
    if len(ans[i]):
        ans[i].sort()
        for j in range(len(ans[i])):
            print("%d"%ans[i][j],end='')
            if j != len(ans[i])-1:
                print(" ",end='')
            else:
                print()
    else:
        print()



