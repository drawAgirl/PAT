a,*b = map(int,input().split())
dic = {}
for each in b:
    dic[each] = dic.get(each,0)+1
flag = True
for each in dic:
    if dic[each] == 1:
        print("%d"%each,end='')
        flag = False
        break
if flag:
    print("None")