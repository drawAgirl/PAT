a = input()
b = input()
dic = {}
miss = 0
cnt = 0
for each in a:
    dic[each] = dic.get(each,0)+1
for each in b:
    if dic.get(each) == None:
        miss = miss + 1
    else:
        cnt = cnt + 1
        dic[each] = dic.get(each)-1
        if dic[each] == 0:
            del dic[each]
if miss:
    print("No %d"%miss)
else:
    print("Yes %d"%(len(a)-cnt))