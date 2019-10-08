from operator import itemgetter
n,m = map(int,input().split())
data = []
for _ in range(n):
    name,age,worth = input().split()
    age = int(age)
    worth = int(worth)
    data.append([name,age,-worth])
data.sort(key=itemgetter(2,1,0))
age = [0 for i in range(201)]
df = []
for each in data:
    if age[each[1]] < 100:
        age[each[1]] += 1
        df.append(each)
for i in range(1,m+1):
    k,c1,c2 = map(int,input().split())
    print("Case #%d:"%i)
    num = 0
    for j in range(len(df)):
        if num >= k:
            break
        if df[j][1] >= c1 and df[j][1] <= c2:
            num += 1
            print("{} {} {}".format(df[j][0],df[j][1],-df[j][2]))
    if num == 0:
        print("None")