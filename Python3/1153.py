from operator import itemgetter
n,m = map(int,input().split())
nodes = []
for _ in range(n):
    id,score = input().split()
    nodes.append([id,-int(score)])
for i in range(1,m+1):
    a,b = input().split()
    print("Case %d: "%i,end='')
    print(a,b)
    ans = []
    if a == '1':
        for node in nodes:
            if node[0][0] == b:
                ans.append(node)
        ans.sort(key=itemgetter(1,0))
        for each in ans:
            print(each[0],-each[1])
        if len(ans) == 0:
            print("NA")
    elif a == '2':
        cnt = 0
        total = 0
        for node in nodes:
            if node[0][1:4] == b:
                cnt += 1
                total +=  node[1]
        if cnt == 0:
            print("NA")
        else:
            print(cnt,-total)
    else:
        dic = {}
        for node in nodes:
            date = node[0][4:10]
            if date == b:
                test = node[0][1:4]
                if dic.get(test) is None:
                    dic[test] = 0
                dic[test] -= 1
        ans = sorted(dic.items(),key=itemgetter(1,0))
        if len(dic) == 0:
            print("NA")
        else:
            for each in ans:
                print(each[0],-each[1])


