from operator import itemgetter
n,k = map(int,input().split())
data = list(map(int,input().split()))
TIMES = {data[0]:-1}
for num in data[1:]:
    print("%d:"%num,end='')
    cur = sorted(TIMES.items(),key=itemgetter(1,0))
    for i,j in enumerate(cur):
        if i == k:
            break
        print(" %d"%j[0],end='')
    print()
    if TIMES.get(num) is None:
        TIMES[num] = 0
    TIMES[num] -= 1

