from operator import itemgetter
n=int(input())
dic = []
for _ in range(n):
    name,id,score = input().split()
    dic.append((name,id,int(score)))
low,high = map(int,input().split())
dic.sort(key=itemgetter(2),reverse=True) # itemgetter比lambda更快一点
if dic[0][2] < low:
    print("NONE")
else:
    for each in dic:
        if each[2] <= high and each[2] >= low:
            print(each[0],each[1])
        elif each[2] < low:
            break