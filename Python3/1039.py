n,k = map(int,input().split())
dic = {}
for _ in range(k):
    a,b = map(int,input().split())
    names = input().split()
    for name in names:
        if dic.get(name) is None:
            dic[name] = []
        dic[name].append(a)
querys = input().split()
for query in querys:
    try:
        size = len(dic[query])
    except:
        size = 0
    print("{} {}".format(query,size),end='')
    if size:
        dic[query].sort()
        for course in dic[query]:
            print(" %d"%course,end='')
    print()