n,m = map(int,input().split())
number = list(map(int,input().split()))
dic = {}
for each in number:
    dic[each] = dic.get(each,0)+1
number.sort()
flag = True
for each in number:
    if dic.get(m-each) != None:
        if m-each == each:
            if dic[each] < 2:
                continue
        print("%d %d"%(min(each,m-each),max(each,m-each)))
        flag = False
        break
if flag:
    print("No Solution")

