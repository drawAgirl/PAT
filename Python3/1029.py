_,*a = map(int,input().split())
_,*b = map(int,input().split())
mid = (len(a)+len(b)-1)>>1
a.append(1000000000) #防止越界
b.append(1000000000)
i = 0
j = 0
index = 0
while index < mid:
    if a[i] < b[j]:
        i += 1
    else:
        j += 1
    index += 1
if a[i]<b[j]:
    print(a[i])
else:
    print(b[j])