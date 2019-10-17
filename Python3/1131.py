n=int(input())
lines = [None]
which_line = {}
graph = {}
vis = {}
for i in range(1,n+1):
    _,*line = map(int,input().split())
    a = line[0]
    vis[a] = False
    for each in line[1:]:
        vis[each] = False
        which_line[(a,each)] = i
        which_line[(each,a)] = i
        if graph.get(a) is None:
            graph[a] = []
        if graph.get(each) is None:
            graph[each] = []
        graph[a].append(each)
        graph[each].append(a)
        a = each
    lines.append(line)

def dfs(start,destination,step,pre_line):
    global vis,temp_path,min_step,path,trans_line,best_line,trans_node,node
    if(vis[start] or step > min_step): return
    if start == destination:
        if step < min_step:
            min_step = step
            path = temp_path[:]
            best_line = trans_line[:]
            node = trans_node[:]
        elif step == min_step and len(trans_line) < len(best_line):
            best_line = trans_line[:]
            path = temp_path[:]
            node = trans_node[:]
        return
    vis[start] = True
    temp_path.append(start)
    for next_station in graph[start]:
        origin_line = pre_line
        cur = which_line[(start,next_station)]
        flag = False
        if cur != pre_line:
            trans_line.append(cur)
            pre_line = cur
            flag = True
            trans_node.append(start)
        dfs(next_station,destination,step+1,pre_line)
        if flag:
            pre_line = origin_line
            trans_line.pop()
            trans_node.pop()
    temp_path.pop()
    vis[start] = False

k = int(input())
for _ in range(k):
    for each in vis:
        vis[each] = False
    start,destination = map(int,input().split())
    min_step = 10000
    temp_path = []
    path = []
    trans_line = []
    best_line = []
    node = []
    trans_node=[]
    dfs(start,destination,0,-1)
    print(min_step)
    for i in range(len(node)):
        print("Take Line#{} from {:04d} to ".format(best_line[i],node[i]),end='')
        if i != len(node) - 1:
            print("{:04d}.".format(node[i+1]))
        else:
            print("{:04d}.".format(destination))
