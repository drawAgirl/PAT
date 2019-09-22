day=["MON","TUE","WED","THU","FRI","SAT","SUN"]
a = input()
b = input()
c = input()
d = input()
length = min(len(a),len(b))

for i in range(length):
    if a[i] == b[i]:
        if a[i]>='A' and a[i]<='G':
            dd = day[ord(a[i])-ord('A')]
            position = i
            break
for i in range(position+1,length):
    if a[i] == b[i]:
        if a[i] >='A' and a[i]<='N':
            hour = ord(a[i])-ord('A')+10
            break
        elif a[i]>='0' and a[i]<='9':
            hour = ord(a[i])-ord('0')
            break
length = min(len(c),len(d))
for i in range(length):
    if c[i] == d[i]:
        if c[i]>='a' and c[i] <='z':
            minute = i
            break
        elif c[i]>='A' and c[i]<='Z':
            minute = i
            break
print("%s %02d:%02d"%(dd,hour,minute))