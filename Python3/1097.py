head,n = map(int,input().split())
data = {}
next = {}
dic = {}
for _ in range(n):
    a,b,c = map(int,input().split())
    data[a] = b
    next[a] = c
first = [] #存储筛选后的链表地址
second = [] #存储删除的链表地址
while head != -1:
    if dic.get(abs(data[head])) == None:
        dic[abs(data[head])] = 1
        first.append(head)
    else:
        second.append(head)
    head = next[head]
if len(second) == 0:
    for i in range(len(first)-1):
        print("%05d %d %05d"%(first[i],data[first[i]],first[i+1]))
    print("%05d %d -1"%(first[-1],data[first[-1]]))
else:
    for i in range(len(first) - 1):
        print("%05d %d %05d" % (first[i], data[first[i]], first[i+1]))
    print("%05d %d -1" % (first[-1], data[first[-1]]))
    for i in range(len(second)-1):
        print("%05d %d %05d"%(second[i],data[second[i]],second[i+1]))
    print("%05d %d -1"%(second[-1],data[second[-1]]))

