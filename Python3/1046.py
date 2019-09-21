_,*dis = map(int,input().split())
n = int(input())
total = 0
accumulate = []
for i,j in enumerate(dis):
    total = total + dis[i]
    accumulate.append(total)
accumulate.insert(0,0)
def swap(a,b):
    return (b,a)
for _ in range(n):
    a,b = map(int,input().split())
    if(a > b):
        a,b=swap(a,b)
    temp = accumulate[b-1]-accumulate[a-1]
    print("%d"%min(temp,total-temp))