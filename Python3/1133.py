from operator import attrgetter
head,n,k = map(int,input().split())
link = {}
Nodes = []
class node:
    def __init__(self,address,val,next_address):
        self.address = address
        self.val = val
        self.next = next_address
        self.invalid = True
        self.priority = 1e7
        self.order = 1e7

for _ in range(n):
    address,val,next_address = map(int,input().split())
    cur = node(address,val,next_address)
    link[address] = cur
    Nodes.append(cur)

cnt = 0
while head != -1:
    cnt += 1
    link[head].invalid = False
    link[head].order = cnt
    if link[head].val < 0:
        link[head].priority = 1
    elif link[head].val <= k:
        link[head].priority = 2
    else:
        link[head].priority = 3
    head = link[head].next
Nodes.sort(key=attrgetter('invalid','priority','order'))
for i in range(len(Nodes)):
    if i == cnt: break
    print("%05d %d"%(Nodes[i].address,Nodes[i].val),end=' ')
    if i!= cnt-1 and i != len(Nodes)-1:
        print("%05d"%Nodes[i+1].address)
    else:
        print("-1")