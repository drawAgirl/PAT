n,m = map(int,input().split())
graph = {}
for _ in range(m):
    a,b = map(int,input().split())
    graph[(a,b)] = 1
    graph[(b,a)] = 1
k = int(input())
for _ in range(k):
    _,*number = map(int,input().split())
    vis = {x:True for x in number}
    isclique = True
    for i in range(len(number)-1):
        if isclique == False:   break
        for j in range(i+1,len(number)):
            if graph.get((number[i],number[j])) is None:
                isclique = False
                break
    if isclique == False:
        print("Not a Clique")
        continue
    flag = False
    for i in range(1,n+1):
        if vis.get(i) is not None:
            continue
        ismaximal = False
        for each in number:
            if graph.get((each,i)) is None:
                break
            if each == number[-1]:
                ismaximal = True
        if ismaximal:
            flag = True
            break
    if flag:
        print("Not Maximal")
    else:
        print("Yes")
