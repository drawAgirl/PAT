from operator import itemgetter
n,m = map(int,input().split())
dic = {}
friends = {}
for _ in range(m):
    a,b=input().split()
    aa = abs(int(a))
    bb = abs(int(b))
    if len(a) == len(b):
        if dic.get(aa) is None:
            dic[aa] = []
        if dic.get(bb) is None:
            dic[bb] = []
        dic[aa].append(bb)
        dic[bb].append(aa)
    friends[(aa,bb)] = 1
    friends[(bb,aa)] = 1
k = int(input())
for _ in range(k):
    ans = []
    a,b = map(int,input().split())
    aa = abs(a)
    bb = abs(b)
    if dic.get(aa) is None:
        print("0")
        continue
    for each in dic[aa]:
        if bb == each:
            continue
        for one in dic[bb]:
            if one == aa:
                continue
            if friends.get((each,one)) is not None:
                ans.append((each,one))
    ans.sort(key=itemgetter(0,1))
    print(len(ans))
    for each in ans:
        print("%04d %04d"%(each[0],each[1]))