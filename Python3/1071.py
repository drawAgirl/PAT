import re
from operator import itemgetter
sentence = list(input())
dic = {}
def check(s):
    if ord(s)>=ord('a') and ord(s) <=ord('z'):
        return True
    if ord(s) >=ord('0') and ord(s) <=ord('9'):
        return  True
    return  False
temp=''
for each in sentence:
    if ord(each) >=ord('A') and ord(each) <=ord('Z'):
        each = chr(ord(each)+32)
    if check(each):
        temp += each
        if len(sentence) == 1:
            dic[temp] = 1
    else:
        if temp=='':
            continue
        if dic.get(temp) is None:
            dic[temp] = 1
        else:
            dic[temp] += 1
        temp =''
b=sorted(dic.items(),key=itemgetter(1),reverse=True)
print(b[0][0],b[0][1])