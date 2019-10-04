n,k = map(int,input().split())
dic ={i:[] for i in range(1,k+1)}
for _ in range(n):
    name,_,*courses = input().split()
    for course in courses:
        dic[int(course)].append(name)
for i in range(1,k+1):
    print("{} {}".format(i,len(dic[i])))
    dic[i].sort()
    for name in dic[i]:
        print(name)