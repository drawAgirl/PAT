from queue import Queue
m,n,l,t = map(int,input().split())
MAP = [[ [] for j in range(m)] for i in range(l)]
vis =[[[False for k in range(n)] for j in range(m)] for i in range(l)]
dir = [[1,0,0],[-1,0,0],[0,-1,0],[0,1,0],[0,0,-1],[0,0,1]]
ans = 0
for i in range(l):
    for j in range(m):
        cur = list(map(int,input().split()))
        MAP[i][j] = cur
for i in range(l):
    for j in range(m):
        for k in range(n):
            if MAP[i][j][k] == 1:
                vis[i][j][k] = True
                q = Queue()
                q.put((i,j,k))
                now = 0
                while q.qsize():
                    now+=1
                    cur = q.get()
                    for d in dir:
                        x = cur[0] + d[0]
                        y = cur[1] + d[1]
                        z = cur[2] + d[2]
                        if x < 0 or x>=l or y<0 or y>=m or z<0 or z>=n:
                            continue
                        if MAP[x][y][z] == 0 or vis[x][y][z]:
                            continue
                        vis[x][y][z] = True
                        q.put((x,y,z))
                if now < t:
                    continue
                ans += now
print(ans)