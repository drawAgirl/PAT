from operator import itemgetter
n,c = map(int,input().split())
dic = []
for i in range(n):
    a = input().split()
    dic.append(a)
if c==1:
    dic.sort(key=itemgetter(0))
elif c==2:
    dic.sort(key=itemgetter(1,0))
else:
    dic.sort(key=itemgetter(2,0))
for each in dic:
    print("{} {} {}".format(each[0],each[1],each[2]))
