from operator import attrgetter
p,m,n = map(int,input().split())
dic = {}
idx = 0
nodes = []
class node:
    def __init__(self,name,online):
        self.name = name
        self.online = online
        self.mid = -1
        self.final = -1
        self.score = -1

for _ in range(p):
    name,score=  input().split()
    if int(score) < 200:
        continue
    dic[name] = idx
    idx += 1
    nodes.append(node(name,int(score)))

for _ in range(m):
    name,score = input().split()
    if dic.get(name) is None:
        continue
    nodes[dic[name]].mid = int(score)

for _ in range(n):
    name,score = input().split()
    if dic.get(name) is None:
        continue
    score = int(score)
    nodes[dic[name]].final = score
    if nodes[dic[name]].mid > score:
        nodes[dic[name]].score=  -1*int(nodes[dic[name]].mid*0.4+0.6*score+0.5)
    else:
        nodes[dic[name]].score = -score
nodes.sort(key=attrgetter('score','name'))
for node in nodes:
    if -node.score < 60:
        break
    print(node.name,node.online,node.mid,node.final,-node.score)
