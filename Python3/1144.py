n=int(input())
number = list(map(int,input().split()))
dic={x:True for x in number if x>0 and x<100010}
for i in range(1,100010):
    if dic.get(i) is None:
        print(i)
        break