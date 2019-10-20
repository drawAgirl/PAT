n,m = map(int,input().split())
g ={i:[] for i in range(n)}
for _ in range(m):
    a,b = map(int,input().split())
    g[a].append(b)
    g[b].append(a)
k=int(input())
for _ in range(k):
    colors = list(map(int,input().split()))
    flag = True
    for i in range(len(colors)):
        for each in g[i]:
            if colors[each] == colors[i]:
                flag = False
                break
        if flag == False:
            break
    if flag == False:
        print("No")
    else:
        print(len(set(colors)),end='-coloring\n')
