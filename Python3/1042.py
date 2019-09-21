n = int(input())
order = list(map(int,input().split()))
flower = ['S','H','C','D','J']
order.insert(0,-1) # 这里填充第一个空格
card = [i for i in range(55)]
result = card.copy()
while n:
    n = n - 1
    for i in range(1,55):
        result[order[i]] = card[i]
    card = result.copy()


for i in range(1,55):
    if result[i]<=13:
        print("S%d"%result[i],end='')
    elif result[i]<=26:
        print("H%d"%(result[i]-13),end='')
    elif result[i]<=39:
        print("C%d"%(result[i]-26),end='')
    elif result[i]<=52:
        print("D%d"%(result[i]-39),end='')
    else:
        print("J%d"%(result[i]-52),end='')
    if(i != 54):
        print(" ",end='')
