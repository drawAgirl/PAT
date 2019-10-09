n = int(input())
data = [-1]
for i in range(1,n+1):
    _,*num = map(int,input().split())
    num = set(num)
    data.append(num)
k = int(input())
for _ in range(k):
    a,b= map(int,input().split())
    print("{:.1f}%".format(len(data[a]&data[b])/len(data[a]|data[b])*100))