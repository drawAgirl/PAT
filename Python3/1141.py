from operator import itemgetter
n=int(input())
school_dic = {}
for _ in range(n):
    id,score,school = input().split()
    school = school.lower()
    if school_dic.get(school) is None:
        school_dic[school] = [0,0]
    school_dic[school][1] += 1
    if id[0] == 'A':
        school_dic[school][0] -= int(score)
    elif id[0] =='B':
        school_dic[school][0] -= int(int(score)/(1.5))
    else:
        school_dic[school][0] -= int(int(score)*1.5)

ans = sorted(school_dic.items(),key=itemgetter(1,0))
rank = 1
pre_rank = 1
print(len(ans))
print(1,ans[0][0],-ans[0][1][0],ans[0][1][1])
for i in range(1,len(ans)):
    rank += 1
    if ans[i][1][0] == ans[i-1][1][0]:
        print(pre_rank,ans[i][0],-ans[i][1][0],ans[i][1][1])
    else:
        pre_rank = rank
        print(rank,ans[i][0],-ans[i][1][0],ans[i][1][1])