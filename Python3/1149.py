n,m = map(int,input().split())
goods ={}
for _ in range(n):
    a,b = map(int,input().split())
    if goods.get(a) is None:
        goods[a] = []
    if goods.get(b) is None:
        goods[b] = []
    goods[a].append(b)
    goods[b].append(a)
for _ in range(m):
    __,*cur_goods = map(int,input().split())
    exists = {x:True for x in cur_goods}
    flag = False
    for good in cur_goods:
        if goods.get(good) is None: continue
        for each in goods[good]:
            if exists.get(each) is not None:
                flag = True
                break
        if flag:    break
    if flag:
        print("No")
    else:
        print("Yes")