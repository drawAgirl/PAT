from operator import attrgetter
n,k,m = map(int,input().split())
score = list(map(int,input().split()))
dic = {i:None for i in range(1,n+1)}
class node:
    def __init__(self,id):
        self.id = id
        self.score = [-2 for i in range(k+1)]
        self.flag = False
        self.perfect = 0
        self.total = 0
        self.rank = 0
for _ in range(m):
    id,problem,grades = map(int,input().split())
    cur = node(id)
    if dic.get(id) is None:
        dic[id] = cur
    if grades > -1:
        dic[id].flag = True
    dic[id].id = -id
    dic[id].score[problem] = max(dic[id].score[problem],grades)
ans = []
for key,values in dic.items():
    if values is None or values.flag == False:
        continue
    for i in range(1,k+1):
        if values.score[i] >0:
            values.total += values.score[i]
            if values.score[i] == score[i-1]:
                values.perfect +=1
    ans.append(values)
ans = sorted(ans,key=attrgetter('total','perfect','id'),reverse=True)
rank = 2
ans[0].rank = 1
for i in range(1,len(ans)):
    if ans[i].total == ans[i-1].total:
        ans[i].rank = ans[i-1].rank
    else:
        ans[i].rank = rank
    rank += 1
for each in ans:
    print(each.rank,"%05d"%(-each.id),each.total,end='')
    for i in range(1,k+1):
        if each.score[i] >=0:
            print(" %d"%each.score[i],end='')
        elif each.score[i] == -1:
            print(" 0",end='')
        else:
            print(" -",end='')
    print()